#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../includes/general/window.h"
#include "../includes/player/actions.h"
#include "../includes/player/bullet.h"
#include "../includes/player/bulletActions.h"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    window_t *window = malloc(sizeof(window_t));
    window_init(window);

    window->player = malloc(sizeof(PlayerStruct));
    PlayerActions playerActions = {
        .InitPlayer = InitPlayer,
        .MovePlayer = MovePlayer,
        .RotatePlayerByMousePosition = RotatePlayerByMousePosition,
        .UpdatePlayer = UpdatePlayer,
    };
    playerActions.InitPlayer(window->player, window->renderer);
    BulletActions bulletActions = {
        .Init = Init,
        .Update = Update,
        .Render = Render,
        .Destroy = Destroy,
    };

    while (window->isRunning)
    {
        window->shootCooldown++;

        SDL_PollEvent(&window->event);

        if (window->event.key.keysym.sym == SDLK_SPACE && window->shootCooldown >= window->shootCooldownMax)
        {
            window->shootCooldown = 0;
            printf("Key pressed: %d", window->event.key.keysym.sym);
            window->bullets[window->bulletIndex] = malloc(sizeof(BulletStruct));
            bulletActions.Init(window->bullets[window->bulletIndex], window->bulletIndex, window->renderer, window->player->pos_x, window->player->pos_y, window->player->textureSkinAngle);
            window->bulletIndex++;
        }

        window_actions(window, window->event);

        playerActions.MovePlayer(window, window->event);
        playerActions.RotatePlayerByMousePosition(window->player);

        SDL_RenderClear(window->renderer);

        window_background(window);

        for (int i = 0; i < window->bulletIndex; i++)
        {
            bulletActions.Update(window->bullets[i], i);
            bulletActions.Render(window->bullets[i], window->renderer);
        }

        playerActions.UpdatePlayer(window->player, window->renderer);
        window_render(window);
    }

    window_destroy(window);

    return 0;
}