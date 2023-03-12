///@author: Pablo Prieto Rodriguez

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

/** @brief Scene manager
*
* Scene's selector
*
* @return scene Current scene displayed
* @return emiter_pool Emitter's pool object in the scene
* @return texture Texture object added to the emitter when created
*/
void SceneManager(int* scene, EmitterPool* emitter_pool, Texture* texture);

/** @brief Emitter manager
*
* IMGUI emitter's options manager
*
* @return emitter Emitter object being managed
* @return texture Emitter's texture
* @return index Emitter's index ID
*/
void EmitterManager(Emitter* emitter, Texture* texture, Uint32 index);

#endif
