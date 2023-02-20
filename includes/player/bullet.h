
#ifndef BULLET_H
#define BULLET_H

#include "../graphic.h"
// #include "../general/window.h"

typedef struct BulletStruct
{
    SDL_Surface *image;
    SDL_Texture *texture;
    SDL_FRect rect;
    SDL_Point textureSkinCenter;
    SDL_RendererFlip textureSkinFlip;
    float textureSkinAngle;

    float pos_x, pos_y;
    float speed_x, speed_y;

} BulletStruct;

#endif