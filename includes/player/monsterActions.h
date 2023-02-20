
// #include "../../includes/general/window.h"
#include "../../includes/player/monster.h"
// #include "../../includes/graphic.h"

//  function to init bullet
static void InitMonster(MonsterStruct *self, int index, SDL_Renderer *renderer, int pos_x, int pos_y, float angle)
{
    (void)index;

    self->image = IMG_Load("/Users/antonin/Desktop/SDL/assets/imgs/monster.png");
    self->texture = SDL_CreateTextureFromSurface(renderer, self->image);

    SDL_FreeSurface(self->image);

    self->textureSkinAngle = angle;

    self->textureSkinCenter.x = 32;
    self->textureSkinCenter.y = 32;

    self->textureSkinFlip = SDL_FLIP_NONE;

    self->pos_x = pos_x;
    self->pos_y = pos_y;

    self->rect.x = self->pos_x;
    self->rect.y = self->pos_y;
    self->rect.w = 64;
    self->rect.h = 64;

    float angleRad = angle * (M_PI / 180);
    float angleCos = cosf(angleRad);
    float angleSin = sinf(angleRad);

    printf("angle: %f\n", angle);
    printf("angleRad: %f\n", angleRad);
    printf("angleCos: %f\n", angleCos);
    printf("angleSin: %f\n", angleSin);

    float speed = 2.0f;

    // self->speed_x = angleCos * speed;
    // self->speed_y = angleSin * speed;

    self->speed_x = speed;
    self->speed_y = speed;
}

static void UpdateMonster(MonsterStruct *self, int index)
{
    self->pos_x += self->speed_x;
    self->pos_y += self->speed_y;

    self->rect.x = self->pos_x;
    self->rect.y = self->pos_y;
}

static void RenderMonster(MonsterStruct *self, SDL_Renderer *renderer)
{
    SDL_RenderCopyExF(renderer, self->texture, NULL, &self->rect, self->textureSkinAngle, &self->textureSkinCenter, self->textureSkinFlip);
}

static void DestroyMonster(MonsterStruct *self, int index)
{

    for (int i = 0; i < index; i++)
    {
        SDL_DestroyTexture(self->texture);
        free(self);
    }
}

typedef struct MonsterActions
{
    void (*Init)(MonsterStruct *self, int index, SDL_Renderer *renderer, int pos_x, int pos_y, float angle);
    void (*Update)(MonsterStruct *self, int index);
    void (*Render)(MonsterStruct *self, SDL_Renderer *renderer);
    void (*Destroy)(MonsterStruct *self, int index);

} MonsterActions;
