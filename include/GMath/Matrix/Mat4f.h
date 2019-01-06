#pragma once

namespace gmath
{
	struct Vec3f;
	struct Vec4f;

	class Mat4f
	{
	public:
			//constructs zero 4x4 matrix
		Mat4f();
		Mat4f(float diagonal);
		
		Mat4f& operator*=(const Mat4f& other);
		Mat4f& inverse();

		Vec4f getTranslation4f() const;
		Vec3f getTranslation3f() const;
		void setTranslation(float x, float y, float z);
		void setTranslation(const Vec3f& vec);

		float* getMatrixPtr();

		void print() const;

	private:
		float matrix[4][4];
	};
}