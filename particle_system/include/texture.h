//Author: Pablo Prieto Rodriguez
#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL.h>
#include <SDL_image.h>
#include "vector_2.h"

class Texture {
public:
	~Texture();

/** @brief Texture load
*
* Loads a Texture from memory
*
* @param path The loaded image address in the system
* @param renderer A SDL renderer object used to create the texture
*/

	void loadFromFile(const char* path, SDL_Renderer* renderer);

/** @brief Texture load from buffer
*
* Loads a Texture from a pixel buffer
*
* @param width Value that corresponds to the texture's width
* @param height Value that corresponds to the texture's height
* @param renderer SDL renderer object
* @param pixel_buffer Pixel buffer
* @param pitch The number of bytes in a row of pixel data, including padding between lines
*/

	void loadFromBuffer(Uint32 width, Uint32 height, SDL_Renderer* renderer, Uint32* pixel_buffer, Uint32 pitch = 4);

/** @brief Texture release
*
* Texture release using SDL
*
*/

	void release();

/** @brief Texture width getter
*
* Gets the Texture's width
*
*/

	Uint32 width() const;

/** @brief Texture height getter
*
* Gets the Texture's height
*
*/

	Uint32 height() const;

/** @brief Texture draw
*
* Drawing of a Tetxure using SDL
*
* @param renderer A SDL renderer object
*/
	void draw(SDL_Renderer* renderer);

/** @brief Texture position setter with values
*
* Sets the texture's coordinates with given values
*
* @param x Coordinates value in the X axis
* @param y Coordinates value in the Y axis
*/

	void set_position(float x, float y);

/** @brief Texture position setter with vector
*
* Sets the texture's coordinates with a given vector
*
* @param pos Vec2 that contains the X and Y coordinates values
*/

	void set_position(Vec2 position);

/** @brief Texture rotation setter
*
* Sets the texture rotation's angle with a given value
*
* @param angle Value that corresponds to the angle of rotation of the texture
*/

	void set_rotation(float angle);

/** @brief Texture position getter
*
* Gets the texture's position coordinates
*
* @return texture's position coordinates
*/

	Vec2 position() const;

/** @brief Texture rotation getter
*
* Gets the texture's rotation value
*
* @return texture's rotation angle
*/

	float rotation() const;

/** @brief Texture create
*
* Creates a new texture if the total doesn't
* exceed the limit
*
* @return A texture pointer of the new texture
*/

	static Texture* CreateTexture();
	static const Uint32 kMaxTexture = 32; 

private:
	Texture();
	Texture(const Texture& copy);
	static Uint32 num_textures;

	Vec2 position_;
	float angle_;

	Uint32 width_;
	Uint32 height_;
	SDL_Texture* texture_;

};

#endif