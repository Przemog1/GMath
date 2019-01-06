#include "..\..\include\GMath\Vector\VectorOperations.h"

namespace gmath
{
	Vec2f operator*(float lhs, const Vec2f& rhs)
	{
		return { lhs * rhs.x, lhs * rhs.y };
	}

	Vec2f operator*(const Vec2f& lhs, float rhs)
	{
		return { lhs.x * rhs, lhs.y * rhs };
	}

	Vec3f operator*(float lhs, const Vec3f& rhs)
	{
		return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
	}

	Vec3f operator*(const Vec3f& lhs, float rhs)
	{
		return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
	}

	Vec3f crossProduct(const Vec3f& lhs, const Vec3f& rhs)
	{
		Vec3f result;

		result.x = lhs.y * rhs.z - rhs.y * lhs.z;
		result.y = rhs.x * lhs.z - lhs.x * rhs.z;
		result.z = lhs.x * rhs.y - rhs.x * lhs.y;

		return result;
	}
}