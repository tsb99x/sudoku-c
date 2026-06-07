#pragma once

#include "context.h"

#include <SDL3/SDL.h>

SDL_Texture **digits_create(context_t *ctx);

void digits_destroy(SDL_Texture **digits);

void digits_recache(SDL_Texture **digits,
                    context_t *ctx);
