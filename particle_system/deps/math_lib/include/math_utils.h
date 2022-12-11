#ifndef __MATHUTILS_H__
#define __MATHUTILS_H__ 1

#include <stdlib.h>
#include <math.h>

class MathUtils {
	public:
		static float MathUtils::Clamp(float value, float minVal, float maxVal);
		static int MathUtils::Clamp(int value, int minVal, int maxVal);
		static float MathUtils::RandomFloat(float min, float max);
		static float MathUtils::SetRandomSin(float max, float min);
		static float MathUtils::SetRandomCos(float max, float min);

	private:
		MathUtils();
		MathUtils(const MathUtils& copy);
		~MathUtils();
};
inline MathUtils::MathUtils() {}
inline MathUtils::MathUtils(const MathUtils& copy) { *this = copy; }
inline MathUtils::~MathUtils(){}

inline float MathUtils::Clamp(float value, float minVal, float maxVal) {
	if(value >= maxVal) value = maxVal;
	if(value <= minVal) value = minVal;
	return value;
}

inline int MathUtils::Clamp(int value, int minVal, int maxVal) {
	if(value >= maxVal) value = maxVal;
	if(value <= minVal) value = minVal;
	return value;
}

inline float MathUtils::RandomFloat(float min, float max){
	return ((max - min) * ((float)rand() / (float)RAND_MAX + min));
}

inline float MathUtils::SetRandomCos(float max, float min){
	return cosf((float) min + rand()/(float) (RAND_MAX) * max);
}

inline float MathUtils::SetRandomSin(float max, float min){
	return sinf((float) min + rand()/(float) (RAND_MAX) * max);
}
#endif