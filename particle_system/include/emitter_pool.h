
#ifndef __EMITTER_POOL_H__
#define __EMITTER_POOL_H__ 1

#include <vector>
#include "emitter.h"

class EmitterPool {
public:
	EmitterPool();
	EmitterPool(const EmitterPool& copy);
	~EmitterPool();

private:
	std::vector<Emitter> emitter_pool_;

};

#endif