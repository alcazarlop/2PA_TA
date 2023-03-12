///@author Manuel Alcazar Lopez

#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include <SDL.h>
#include "entity.h"
#include "texture.h"

class Sprite : public Entity {
public:
	Sprite();
	Sprite(const Sprite& copy);
	virtual ~Sprite();

	void init(Vec3 pos, Vec3 scale) override;
	void draw(SDL_Renderer* renderer) override;
	void update() override;

	void set_texture(Texture* tex);
	Texture* texture() const;

private:
	Texture* tex_;
};

#endif
