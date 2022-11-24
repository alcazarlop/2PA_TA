
#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL.h>

class Texture {
public:
	Texture();
	Texture(const Texture& copy);
	~Texture();

	void loadFromFile();
	void loadFromBuffer();

	void getSubTxture()

	Uint32 width() const;
	Uint32 height() const;

private:
	Uint32 width_;
	Uint32 height_;
	
};

#endif