#ifndef _USERLIB_UTILITIES_HPP_
#define _USERLIB_UTILITIES_HPP_
/*
 * utilities.hpp
 *
 *  Created on: May 4, 2023
 *  Recreated on: May 7, 2023 as .hpp file
 *      Author: KaDzejoo
 *  This file contains common useful methods;
 */

/*	float leakyIntegrator(float actual, float last, float a);
 * 	- applies low pass filter at signal given actual and previous sample
 * 		actual - actual signal sample
 * 		last - last seen sample (n-1)
 * 		a - filter effect multiplier
 * 			(01 - slow reaction/ hard filtering
 * 	 		 50 - faster reaction / less filtering )
 */
float leakyIntegrator(float actual, float last, int a);

/*	expoMap(int x,int easingFactor, int offset);
 * 	- applies exponential interpolation to provided signal
 * 		x - input signal
 * 		easingFactor - function curvature (0 - no curvature, 200 - absurd curvature)
 * 		offset - distance to zero e.g. positive 50 offset means that function flat spot
 * 		lies on positive 50,
 * 	@returns float
 */
float expoMap(float x, float easingFactor, int offset);

/*	map(T x, T in_min, T in_max, T out_min, T out_max)
 * 	- maps signal range from in_min and in_max to out_min and out_max
 * 	x - input signal
 */
template <typename T>
inline T const& map(T x, T in_min, T in_max, T out_min, T out_max)
{
	return ( x - in_min ) * ( out_max - out_min ) / ( in_max - in_min ) + out_min;
}

/* constrain(T x, T a, T b) ;
 * - restricts value x to range from a to b
 * x - input signal
 */
template <typename T>
inline T const& constrain(T x, T a, T b)
{
	if (x < a)
	{
		return a;
	}
	else if (b < x)
	{
		return b;
	}
	else
		return x;
}

#endif /* APPLICATION_USER_USERLIB_UTILITIES_H_ */
