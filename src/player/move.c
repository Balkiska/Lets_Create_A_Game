
#include "../../includes/player/player.h"
#include "../../includes/general/window.h"

static void BorderCollision(SDL_Rect backgroundRect, SDL_Rect *playerRect, int x, int y)
{
    if (playerRect->x + x < 0)
    {
        playerRect->x = 0;
    }
    else if (playerRect->x + x > backgroundRect.w - playerRect->w)
    {
        playerRect->x = backgroundRect.w - playerRect->w;
    }
    else if (playerRect->y + y < 0)
    {
        playerRect->y = 0;
    }
    else if (playerRect->y + y > backgroundRect.h - playerRect->h)
    {
        playerRect->y = backgroundRect.h - playerRect->h;
    }
    else
    {
        playerRect->x += x;
        playerRect->y += y;
    }
}

void MovePlayer(window_t *self, SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            BorderCollision(self->backgroundRect, &self->player->rect, 0, -32);
            break;
        case SDLK_DOWN:
            BorderCollision(self->backgroundRect, &self->player->rect, 0, 32);
            break;
        case SDLK_LEFT:
            BorderCollision(self->backgroundRect, &self->player->rect, -32, 0);
            break;
        case SDLK_RIGHT:
            BorderCollision(self->backgroundRect, &self->player->rect, 32, 0);
            break;
        case SDLK_z:
            BorderCollision(self->backgroundRect, &self->player->rect, 0, 0);
            break;
        case SDLK_s:
            BorderCollision(self->backgroundRect, &self->player->rect, 0, 0);
            break;
        case SDLK_q:
            BorderCollision(self->backgroundRect, &self->player->rect, 0, 0);
            break;
        case SDLK_d:
            BorderCollision(self->backgroundRect, &self->player->rect, 0, 0);
            break;
        }
    }
    self->player->pos_x = self->player->rect.x;
    self->player->pos_y = self->player->rect.y;
}
