
#include "../../includes/graphic.h"
#include "../../includes/general/window.h"
#include <stdbool.h>

void window_init(window_t *self)
{
    self->isRunning = true;

    self->width = 1280;
    self->height = 720;

    self->window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, self->width, self->height, SDL_WINDOW_SHOWN);
    self->renderer = SDL_CreateRenderer(self->window, -1, SDL_RENDERER_ACCELERATED);

    self->background = IMG_Load("/Users/antonin/Desktop/SDL/assets/imgs/background.jpg");
    self->backgroundTexture = SDL_CreateTextureFromSurface(self->renderer, self->background);

    self->backgroundRect.x = 0;
    self->backgroundRect.y = 0;
    self->backgroundRect.w = self->width;
    self->backgroundRect.h = self->height;

    self->bulletIndex = 0;
    self->shootCooldown = 0;
    self->shootCooldownMax = 20;
}

void window_background(window_t *self)
{
    SDL_RenderCopy(self->renderer, self->backgroundTexture, NULL, &self->backgroundRect);
}

void window_render(window_t *self)
{
    SDL_RenderPresent(self->renderer);
}

void window_destroy(window_t *self)
{
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    SDL_Quit();
}
