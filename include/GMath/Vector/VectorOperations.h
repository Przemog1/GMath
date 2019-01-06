#pragma once
#include "Vec2f.h"
#include "Vec3f.h"
#include "Vec4f.h"

namespace gmath
{
	Vec2f operator*(float lhs, const Vec2f& rhs);

	Vec2f operator*(const Vec2f& lhs, float rhs);

	Vec3f operator*(float lhs, const Vec3f& rhs);

	Vec3f operator*(const Vec3f& lhs, float rhs);

	Vec3f crossProduct(const Vec3f& lhs, const Vec3f& rhs);

	constexpr float dotProduct(const Vec2f& lhs, const Vec2f& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	constexpr float dotProduct(const Vec3f& lhs, const Vec3f& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}
}

