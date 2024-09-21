#include "pch.h"
#include "../GAUS/MathematicalVector.h"

class MathematicalVectorTest : public ::testing::Test {
protected:
    // Example vectors for use in tests
    MathematicalVector vec1;
    MathematicalVector vec2;

    void SetUp() override {
        // Initialize vectors with example values
        vec1 = std::vector<double>{ 1.0, 2.0, 3.0 };
        vec2 = std::vector<double>({ 0.5, 1.5, 2.0 });
    }
};

// Test for operator -=
TEST_F(MathematicalVectorTest, OperatorMinusEqual) {
    // Arrange
    MathematicalVector expected = std::vector<double>{ 0.5, 0.5, 1.0 };

    // Act
    vec1 -= vec2;

    // Assert
    ASSERT_EQ(vec1.size(), expected.size());
    for (size_t i = 0; i < vec1.size(); ++i) {
        EXPECT_DOUBLE_EQ(vec1[i], expected[i]);
    }
}

// Test for operator * (scalar multiplication)
TEST_F(MathematicalVectorTest, OperatorMultiplyScalar) {
    // Arrange
    double scalar = 2.0;
    MathematicalVector expected = std::vector<double>{ 2.0, 4.0, 6.0 };

    // Act
    MathematicalVector result = vec1 * scalar;

    // Assert
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_DOUBLE_EQ(result[i], expected[i]);
    }
}