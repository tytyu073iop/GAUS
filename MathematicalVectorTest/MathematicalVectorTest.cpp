#include "pch.h"
#include "CppUnitTest.h"
#include "MathematicalVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathematicalVectorTest
{
	TEST_CLASS(MathematicalVectorTest)
	{
	public:
		
		// Test for operator -=
		TEST_METHOD(TestOperatorMinusEqual)
		{
			// Arrange
			MathematicalVector vec1({ 1.0, 2.0, 3.0 });
			MathematicalVector vec2({ 0.5, 1.5, 2.0 });
			MathematicalVector expected({ 0.5, 0.5, 1.0 });

			// Act
			vec1 -= vec2;

			// Assert
			for (size_t i = 0; i < vec1.size(); ++i)
			{
				Assert::AreEqual(expected[i], vec1[i], L"Operator -= failed");
			}
		}

		// Test for operator * (scalar multiplication)
		TEST_METHOD(TestOperatorMultiplyScalar)
		{
			// Arrange
			MathematicalVector vec({ 1.0, 2.0, 3.0 });
			double scalar = 2.0;
			MathematicalVector expected({ 2.0, 4.0, 6.0 });

			// Act
			MathematicalVector result = vec * scalar;

			// Assert
			for (size_t i = 0; i < result.size(); ++i)
			{
				Assert::AreEqual(expected[i], result[i], L"Operator * (scalar) failed");
			}
		}
	};
}
