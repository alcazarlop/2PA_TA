///@author Pablo Prieto Rodriguez

#ifndef __IMGUI_CONTROLLER_H__
#define __IMGUI_CONTROLLER_H__ 1

#include <SDL.h>
#include <stdio.h>
#include <vector>
#include "game_manager.h"
#include "imgui.h"
#include "emitter.h"
#include "emitter_pool.h"
#include "math_utils.h"
#include "texture.h"

void SceneManager(int* scene, EmitterPool* emitter_pool, Texture* texture);
void EmitterManager(Emitter* emitter, Texture* texture, Uint32 index);

#endif
