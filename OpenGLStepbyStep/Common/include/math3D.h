#ifndef _MATH_3D_H_
#define _MATH_3D_H_


#include <stdio.h>


struct Vector3f
{
	float x;
	float y;
	float z;

	Vector3f(){}

	Vector3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f(const float* pFloat)
	{
		x = pFloat[0];
		y = pFloat[1];
		z = pFloat[2];
	}


	void Print() const
	{
		printf("(%.02f, %.02f, %.02f)", x, y, z);
	}
};



#endif // !_MATH_3D_H_
