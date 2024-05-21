{
  description = "Flake for Arduino Development";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    devenv = {
      url = "github:cachix/devenv";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = inputs@{ self, devenv, nixpkgs, ... }:
    let
      systems = [ "x86_64-linux" "x86_64-darwin" "aarch64-linux" "aarch64-darwin" ];
      forAllSystems = f: builtins.listToAttrs (map (name: { inherit name; value = f name; }) systems);
      mkPkgs = system: import nixpkgs {
        inherit system;
        config = {
          allowUnfree = true;
        };
      };

      name = "arduino";
    in
    {
      devShells = forAllSystems (system:
        let
          pkgs = mkPkgs system;

          tools = with pkgs; [
            arduino-cli
            clang-tools
            git
            just
            picocom
            platformio
          ];

          development = with pkgs; [
            valgrind
          ];

          darwinPkgs = with pkgs.darwin.apple_sdk.frameworks; [
            CoreFoundation
            CoreServices
          ];

          arduinoShellHookPaths = ''
            if [ -z ''${XDG_CACHE_HOME:-} ]; then
                export _ARDUINO_ROOT=$HOME/.arduino/${name}
            else
                export _ARDUINO_ROOT=$XDG_CACHE_HOME/arduino/${name}
            fi
            export _ARDUINO_PYTHON3=${pkgs.python3}
            export ARDUINO_DIRECTORIES_USER=$_ARDUINO_ROOT
            export ARDUINO_DIRECTORIES_DATA=$_ARDUINO_ROOT
            export ARDUINO_DIRECTORIES_DOWNLOADS=$_ARDUINO_ROOT/staging
          '';

        in
        {
          # `nix develop .#ci`
          # reduce the number of packages to the bare minimum needed for CI
          ci = pkgs.mkShell {
            buildInputs = tools;
          };

          # `nix develop`
          default = devenv.lib.mkShell {
            inherit inputs pkgs;
            modules = [
              ({ pkgs, lib, ... }: {
                packages =
                  tools
                  ++ development
                  ++ lib.optionals pkgs.stdenv.isDarwin (darwinPkgs);

                scripts = {
                  build.exec = "just ./tasks/build";
                  release.exec = "just ./tasks/release";
                  upload.exec = "just ./tasks/upload";
                  clean.exec = "just ./tasks/clean";
                };

                enterShell = ''
                  ${arduinoShellHookPaths}
                  echo "==> Using arduino-cli version $(arduino-cli version)"
                  echo "    Storing arduino-cli data for this project in '$_ARDUINO_ROOT'"

                  echo "==> Using platformio version $(platformio --version)"

                  just ./tasks/
                '';
              })
            ];
          };
        });
    };
}
