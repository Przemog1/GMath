#include "..\..\include\GMath\Matrix\Transform.h"
#include "..\..\include\GMath\Vector\VectorOperations.h"
#include <math.h>
#include <iostream>

namespace gmath
{
	Mat4f translate(float x, float y, float z)
	{
		Mat4f result(1.0f);

		result(0, 3) = x;
		result(1, 3) = y;
		result(2, 3) = z;

		return result;
	}



	Mat4f translate(const Vec3f& vec)
	{
		Mat4f result(1.0f);

		result(0, 3) = vec.x;
		result(1, 3) = vec.y;
		result(2, 3) = vec.z;

		return result;
	}

	Mat4f rotateX(float radians)
	{
		Mat4f result;

		result(0, 0) =  1.0f;
		result(1, 1) =  cos(radians);
		result(1, 2) = -sin(radians);
		result(2, 2) =  cos(radians);
		result(2, 1) =  sin(radians);

		result(3, 3) =  1.0f;

		return result;
	}

	Mat4f rotateY(float radians)
	{
		Mat4f result;

		result(0, 0) =  cos(radians);
		result(0, 2) =  sin(radians);
		result(1, 1) =  1.0f;
		result(2, 0) = -sin(radians);
		result(2, 2) =  cos(radians);
		result(3, 3) =  1.0f;

		return result;
	}

	Mat4f rotateZ(float radians)
	{
		Mat4f result;

		result(0, 0) =  cos(radians);
		result(0, 1) = -sin(radians);
		result(1, 0) =  sin(radians);
		result(1, 1) =  cos(radians);
		result(2, 2) =  1.0f;
		result(3, 3) =  1.0f;

		return result;
	}

	Mat4f scale(float scalar)
	{
		Mat4f result;

		result(0, 0) = scalar;
		result(1, 1) = scalar;
		result(2, 2) = scalar;
		result(3, 3) = 1.0f;

		return result;
	}

	Mat4f scale(float x, float y, float z)
	{
		Mat4f result;

		result(0, 0) = x;
		result(1, 1) = y;
		result(2, 2) = z;
		result(3, 3) = 1.0f;

		return result;
	}

	Mat4f lookAt(const gmath::Vec3f& from, const gmath::Vec3f& to, const gmath::Vec3f& up)
	{
		const Vec3f forward = getNormalized(from - to);

		const Vec3f right = getNormalized(crossProduct(up, forward));

		const Vec3f upv = crossProduct(forward, right);

		
		right.print();
		upv.print();
		forward.print();

		std::cout << std::endl;

		Mat4f result;

		result(0, 0) = right.x;		result(0, 1) = right.y;		result(0, 2) = right.z;
		result(1, 0) = upv.x;		result(1, 1) = upv.y;		result(2, 2) = upv.z;
		result(2, 0) = forward.x;	result(2, 1) = forward.y;	result(2, 2) = forward.z;

		result(0, 3) = -dotProduct(right, from);
		result(1, 3) = -dotProduct(upv, from);
		result(2, 3) = -dotProduct(forward, from);

		result(3, 3) = 1.0f;

		return result;
	}

	Mat4f ortho(float left, float right, float bottom, float top, float near, float far);

	Mat4f perspective(float FOV, float aspectRatio, float near, float far);
}