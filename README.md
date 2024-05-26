# Duino

[![built with nix](https://builtwithnix.org/badge.svg)](https://builtwithnix.org)

|    Project    |     Directory     |  Status   |
| ------------- | ----------------- | --------- |
| Tasks         | [tasks](./tasks/) | [![Build Project (Tasks)](https://github.com/mtrsk/duino/actions/workflows/build.yml/badge.svg)](https://github.com/mtrsk/duino/actions/workflows/build.yml) |

Playing with arduino in C++ (and maybe Rust), platform.io and Nix. Also wanting to explore some embedded systems stuff, leveraging what I know about Nix.

## Developing

```shell
nix develop --impure
```
as of now, there's only a single `tasks` project. But I plan to add more, increasing complexity and scope.

## Building & Uploading

You can either use the scripts inside the nix development shell:
```shell
build
release
upload
```
or `cd tasks` and use `just`:
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
