//Author: Pablo Prieto Rodriguez
#ifndef __IMGUI_CONTROLLER_H__
#define __IMGUI_CONTROLLER_H__ 1

#include <SDL.h>
#include "imgui.h"
#include "math_utils.h"
#include "emitter_pool.h"
#include "emitter.h"
#include "vector_4.h"

/** @brief Emitter Manager
*
* Shows and manages the ImGui iterface for the creation
* of new emitters
*
* @param emitter_pool Emitter's object pointer which contains the emitter's pool
* @param renderer SDL renderer needed for drawing functions
*/

void EmitterPoolManager(EmitterPool* emitter_pool, SDL_Renderer* renderer);

/** @brief Emitter SetUp
*
* Shows and manages the ImGui iterface for the customization
* of the created emitters
*
* @param emitter Emitter class object that it's being customized
* @param tag Emitter's number
*/

void EmitterSetup(Emitter* emitter, int tag);

/** @brief Emitter Parameters
*
* Shows and manages the ImGui iterface for the customization
* of the emitter's parameters
*
* @param emitter Emitter class object that it's being customized
*/

void EmitterParamsWindow(Emitter* emitter);

#endif
