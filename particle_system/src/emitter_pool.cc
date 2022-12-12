
#include "emitter_pool.h"

EmitterPool::EmitterPool(){
	emitter_pool_.clear();

}

EmitterPool::EmitterPool(const EmitterPool& copy){
	emitter_pool_ = copy.emitter_pool_;
}

EmitterPool::~EmitterPool(){
	emitter_pool_.clear();
}


