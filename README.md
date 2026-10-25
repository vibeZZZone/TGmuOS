# teleSP

Telegram client for Anbernic RG35XX SP (muOS), 640x480, button-driven UI.

## Build (host)

```sh
cmake -S . -B build
cmake --build build
./build/telesp
```

Requires SDL2 and SDL2_ttf dev packages.

## Cross-compile (muOS target)

Toolchain not included. Use an ARM cross-compiler targeting the device's libc,
then package per muOS app layout.
