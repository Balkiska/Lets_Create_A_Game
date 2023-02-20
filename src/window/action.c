
#include "../../includes/general/window.h"
#include <stdbool.h>

void window_actions(window_t *self, SDL_Event event)
{
    if (event.type == SDL_QUIT)
    {
        self->isRunning = false;
    }
}
