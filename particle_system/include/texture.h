///@author: Pablo Prieto Rodriguez

#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL.h>
#include <SDL_image.h>

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

/** @brief Texture create
*
* Creates a new texture if the total doesn't
* exceed the limit
*
* @return A texture pointer of the new texture
*/

	static Texture* CreateTexture();
	static const Uint32 kMaxTexture = 32; 
	static Uint32 avaliableTextures(); 

	SDL_Texture* texture() const;

private:
	Texture();
	Texture(const Texture& copy);

	static Uint32 num_textures;
	Uint32 width_;
	Uint32 height_;
	SDL_Texture* texture_;

};

#endif
