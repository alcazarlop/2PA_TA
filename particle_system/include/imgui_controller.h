//Author: Pablo Prieto Rodriguez
#ifndef __IMGUI_CONTROLLER_H__
#define __IMGUI_CONTROLLER_H__ 1

#include <SDL.h>
#include "imgui.h"
#include "emitter.h"
#include "math_utils.h"

void ChangeScene(int* scene);
void EmitterManager(Emitter* emitter);

#endif
