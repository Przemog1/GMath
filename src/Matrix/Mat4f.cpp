#include "..\..\include\GMath\Matrix\Mat4f.h"
#include "..\..\include\GMath\Vector\Vec3f.h"
#include "..\..\include\GMath\Vector\Vec4f.h"
#include <memory>
#include <iostream>

namespace gmath
{
	Mat4f::Mat4f()
	{
		std::memset(&matrix[0][0], 0, 16 * sizeof(float));
	}

	Mat4f::Mat4f(float diagonal)
	{
		std::memset(&matrix[0][0], 0, 16 * sizeof(float));
		matrix[0][0] = diagonal;
		matrix[1][1] = diagonal;
		matrix[2][2] = diagonal;
		matrix[3][3] = diagonal;
	}

	Mat4f& Mat4f::operator*=(const Mat4f& other) { return *this;  }
	Mat4f& Mat4f::inverse() { return *this; }

	Vec4f Mat4f::getTranslation4f() const
	{
		return Vec4f(matrix[0][3], matrix[1][3], matrix[2][3], matrix[3][3]);
	}
	Vec3f Mat4f::getTranslation3f() const
	{
		return { matrix[0][3], matrix[1][3], matrix[2][3] };
	}
	void setTranslation(float x, float y, float z)
	{

	}
	void setTranslation(const Vec3f& vec)
	{

	}

	float* Mat4f::getMatrixPtr() { return &matrix[0][0]; }

	void Mat4f::print() const
	{
		for (int i = 0; i < 4; i++)
			std::cout << matrix[i][0] << ' ' << matrix[i][1] << ' '
			<< matrix[i][2] << ' ' << matrix[i][3] << '\n';
	}
}