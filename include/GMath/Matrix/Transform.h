#pragma once
#include "MatrixOperations.h"
#include "Mat4f.h"

namespace gmath
{
	Mat4f translate(float x, float y, float z);
	
	Mat4f rotateX(float radians);

	Mat4f rotateY(float radians);

	Mat4f rotateZ(float radians);

	Mat4f scale(float scalar);

	Mat4f scale(float x, float y, float z);

	Mat4f ortho(float left, float right, float bottom, float top, float near, float far);

	Mat4f perspective(float FOV, float aspectRatio, float near, float far);

}