#include "utilities.hpp"
#include <math.h>
#include <stdlib.h>
/*
 * utilities.cpp
 *
 *  Created on: May 4, 2023
 *  Recreated on: May 7, 2023 as .cpp file
 *      Author: KaDzejoo
 *
 *
 */
float leakyIntegrator(float actual, float last, int a)
{
	float ratio = (float) a / 100;

	return ( 1 - ratio ) * last + actual * ratio;
}

float expoMap(float x, float easingFactor, int offset)
{
	// -50 lol xd
	double _x = x - offset;
	double _offset = offset;
	double _easing = easingFactor;
	double val;
	val = exp( ( ( abs(_x) - _offset ) * _easing ) / 1000) * _x;
	return val + _offset;
}

//float map(float x, float in_min, float in_max, float out_min, float out_max)
//{
//	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
//}

//
//long constrain(long x, long a, long b)
//{
//	if(x < a) {
//		return a;
//	}
//	else if(b < x) {
//		return b;
//	}
//	else
//	return x;
//}
