# ADR: teleSP development

## Context
Telegram client for Anbernic RG35XX SP (muOS), 640x480, button-driven.

## Decisions
- Stack: C++17 + SDL2/SDL_ttf, CMake.
- Build via GitHub Actions; artifacts downloadable.
- Ignore build/ in git.
- Deploy via scp/ssh to device.

## Status
Scaffold + CI in place; TDLib integration pending.
