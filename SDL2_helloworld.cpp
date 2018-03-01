/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL
#include <SDL2/SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Surface *screen_surface = nullptr;
SDL_Surface *image = nullptr;

bool init() {
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL couldn't initialize. Error: " << SDL_GetError() << std::endl;
    success = false;
  } else {
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
      std::cout << "Window couldn't be created. Error: " << SDL_GetError() << std::endl;
      success = false;
    } else {
      screen_surface = SDL_GetWindowSurface(window);
    }
  }

  return success;
}

bool loadMedia() {
  bool success = true;

  image = SDL_LoadBMP("ok.bmp");

  if (image == nullptr) {
    std::cout << "Image couldn't be loaded. Error: " << SDL_GetError() << std::endl;
    success = false;
  }

  return success;
}

void close() {
  SDL_FreeSurface(screen_surface);
  screen_surface = nullptr;

  SDL_DestroyWindow(window);
  window = nullptr;

  SDL_Quit();
}

int main(int argc, char* args[]) {
  bool quit = false;
  SDL_Event e;

  if (!init()) {
    std::cout << "Failed to initialize" << std::endl;
  } else {
    if (!loadMedia()) {
      std::cout << "Failed to load media" << std::endl;
    }
  }

  while (!quit) {
    while(SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }

    SDL_BlitSurface(image, nullptr, screen_surface, nullptr);
    SDL_UpdateWindowSurface(window);
  }

  close();
  return 0;

}
