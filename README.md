# Duino

[![built with nix](https://builtwithnix.org/badge.svg)](https://builtwithnix.org)
[![Build Project (State Machine)](https://github.com/mtrsk/duino/actions/workflows/build.yml/badge.svg)](https://github.com/mtrsk/duino/actions/workflows/build.yml)

Playing with arduino in C++ (and maybe Rust), platform.io and Nix.

## Developing

```shell
nix develop --impure
```
as of now, there's only a single `state-machine` project.

## Building & Uploading

You can either use the scripts inside the nix development shell:
```shell
build
release
upload
```
or `cd state-machine` and use `just`:
```shell
just build
just release
just upload
```

## Debugging

```shell
just monitor
# or monitor
```

## Notes

For `NixOS` only, make sure your user is in the `dialout` group.
