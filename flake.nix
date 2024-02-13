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
      supportedSystems = [ "x86_64-linux" "x86_64-darwin" "aarch64-darwin" ];

      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;

      nixpkgsFor = forAllSystems (system: import nixpkgs {
        inherit system;
      });

      name = "arduino";
    in
    {
      devShells = forAllSystems (system:
        let
          pkgs = nixpkgsFor."${system}";
          inherit (pkgs);

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
            buildInputs = with pkgs; [ bash gnumake platformio ];
          };

          # `nix develop`
          default = devenv.lib.mkShell {
            inherit inputs pkgs;
            modules = [
              ({ pkgs, lib, ... }: {
                packages = with pkgs; [
                  arduino-cli
                  bash
                  clang-tools
                  git
                  gnumake
                  picocom
                  platformio
                ];

                enterShell = ''
                  ${arduinoShellHookPaths}
                  echo "==> Using arduino-cli version $(arduino-cli version)"
                  echo "    Storing arduino-cli data for this project in '$_ARDUINO_ROOT'"

                  echo "==> Using platformio version $(platformio --version)"
                '';

                # looks for the .env by default
                dotenv.enable = true;
              })
            ];
          };
        });
    };
}
