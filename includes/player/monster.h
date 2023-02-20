
#ifndef MONSTER_H
#define MONSTER_H

#include "../graphic.h"
// #include "../general/window.h"

typedef struct MonsterStruct
{
    SDL_Surface *image;
    SDL_Texture *texture;
    SDL_FRect rect;
    SDL_Point textureSkinCenter;
    SDL_RendererFlip textureSkinFlip;
    float textureSkinAngle;

    float pos_x, pos_y;
    float speed_x, speed_y;

} MonsterStruct;

#endif