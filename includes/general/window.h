#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "player/player.h"
#include "player/bullet.h"

typedef struct
{
    // Window
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_Surface *background;
    SDL_Texture *backgroundTexture;
    SDL_Rect backgroundRect;

    int width;
    int height;

    // Game
    bool isRunning;
    int shootCooldown;
    int shootCooldownMax;

    // Player
    PlayerStruct *player;
    BulletStruct *bullets[100];
    int bulletIndex;

} window_t;

void window_init(window_t *window);
void window_background(window_t *window);
void window_actions(window_t *window, SDL_Event event);
void window_render(window_t *window);
void window_destroy(window_t *window);
void window_renderBullets(window_t *window);

#endif