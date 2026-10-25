#pragma once
#include <SDL2/SDL.h>
enum class ScreenId { Chats, Chat, Auth, Settings };
class Screen { public: virtual ~Screen()=default; virtual void handle(const SDL_Event&)=0; virtual void update()=0; virtual void render(SDL_Renderer*)=0; };
