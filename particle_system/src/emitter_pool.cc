
#include "emitter_pool.h"

EmitterPool::EmitterPool(){
	isBinded_ = false;
}

EmitterPool::EmitterPool(const EmitterPool& copy){
	isBinded_ = copy.isBinded_;
	pool_ = copy.pool_;
}

EmitterPool::~EmitterPool(){
	for(unsigned int i = 0; i < pool_.size(); ++i)
		delete pool_[i];
	pool_.clear();
}
