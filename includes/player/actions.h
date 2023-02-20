
#ifndef PLAYER_ACTIONS_H
#define PLAYER_ACTIONS_H

#include "../graphic.h"
#include "player.h"

static void InitPlayer(PlayerStruct *self, SDL_Renderer *renderer)
{
    (void)renderer;
    (void)self;
    self->image = IMG_Load("/Users/antonin/Desktop/SDL/assets/imgs/player.png");
    self->texture = SDL_CreateTextureFromSurface(renderer, self->image);

    SDL_FreeSurface(self->image);

    self->textureSkinAngle = 180.0f;
    self->textureSkinCenter.x = 32;
    self->textureSkinCenter.y = 32;
    self->textureSkinFlip = SDL_FLIP_NONE;

    self->pos_x = 0;
    self->pos_y = 0;

    self->rect.x = self->pos_x;
    self->rect.y = self->pos_y;
    self->rect.w = 64;
    self->rect.h = 64;
}

static void UpdatePlayer(PlayerStruct *self, SDL_Renderer *renderer)
{
    SDL_RenderCopyEx(renderer, self->texture, NULL, &self->rect, self->textureSkinAngle, &self->textureSkinCenter, self->textureSkinFlip);
}

static void RotatePlayerByMousePosition(PlayerStruct *self)
{
    (void)self;
    int x, y;
    SDL_GetMouseState(&x, &y);

    self->textureSkinAngle = atan2(y - self->rect.y, x - self->rect.x) * 180 / M_PI;
}

void MovePlayer(PlayerStruct *self, SDL_Event event);

typedef struct PlayerActions
{
    void (*InitPlayer)(PlayerStruct *self, SDL_Renderer *renderer);
    void (*UpdatePlayer)(PlayerStruct *self, SDL_Renderer *renderer);
    void (*MovePlayer)(window_t *self, SDL_Event event);
    void (*RotatePlayerByMousePosition)(PlayerStruct *self);
} PlayerActions;

#endif