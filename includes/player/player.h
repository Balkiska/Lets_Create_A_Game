
#ifndef PLAYER_H
#define PLAYER_H

#include "../graphic.h"

typedef struct PlayerStruct
{
    SDL_Surface *image;
    SDL_Texture *texture;
    SDL_Rect rect;
    SDL_Point textureSkinCenter;
    SDL_RendererFlip textureSkinFlip;
    float textureSkinAngle;

    int pos_x, pos_y;

} PlayerStruct;

#endif