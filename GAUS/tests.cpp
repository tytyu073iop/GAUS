#include "Tests.h"
#include <iostream>
#include <cassert>

// Function to test the MathematicalVector class
void testMathematicalVector() {
    // Test operator-=
    {
        MathematicalVector v1({ 1.0, 2.0, 3.0 });
        MathematicalVector v2({ 0.5, 1.0, 1.5 });

        v1 -= v2;

        // Expected result after v1 -= v2
        std::vector<double> expected = { 0.5, 1.0, 1.5 };

        // Check if v1 contains the expected result
        for (size_t i = 0; i < expected.size(); ++i) {
            assert(v1[i] == expected[i]);  // Use assert to check each element
        }
        std::cout << "operator-= test passed!" << std::endl;
    }

    // Test operator* (scalar multiplication)
    {
        MathematicalVector v({ 1.0, 2.0, 3.0 });
        double scalar = 2.0;

        MathematicalVector result = v * scalar;

        // Expected result after v * scalar
        std::vector<double> expected = { 2.0, 4.0, 6.0 };

        // Check if result contains the expected result
        for (size_t i = 0; i < expected.size(); ++i) {
            assert(result[i] == expected[i]);  // Use assert to check each element
        }
        std::cout << "operator* (scalar multiplication) test passed!" << std::endl;
    }
}

// Function to test the Matrix class
void testMatrix() {
    // Test constructor and size()
    {
        // Create a sample matrix
        matrixType mat = {
            MathematicalVector({1.0, 2.0, 3.0}),
            MathematicalVector({4.0, 5.0, 6.0}),
            MathematicalVector({7.0, 8.0, 9.0})
        };

        // Create Matrix object
        Matrix m(mat);

        // Test size()
        assert(m.size() == 3);
        std::cout << "Matrix size test passed!" << std::endl;
    }

    // Test operator[] for accessing rows
    {
        // Create a sample matrix
        matrixType mat = {
            MathematicalVector({1.0, 2.0, 3.0}),
            MathematicalVector({4.0, 5.0, 6.0}),
            MathematicalVector({7.0, 8.0, 9.0})
        };

        Matrix m(mat);

        // Access and test first row
        MathematicalVector row0 = m[0];
        assert(row0[0] == 1.0 && row0[1] == 2.0 && row0[2] == 3.0);

        // Access and test second row
        MathematicalVector row1 = m[1];
        assert(row1[0] == 4.0 && row1[1] == 5.0 && row1[2] == 6.0);

        std::cout << "Matrix operator[] test passed!" << std::endl;
    }

    // Test swapElementsByVertical (swapping two rows)
    {
        // Create a sample matrix
        matrixType mat = {
            MathematicalVector({1.0, 2.0, 3.0}),
            MathematicalVector({4.0, 5.0, 6.0}),
            MathematicalVector({7.0, 8.0, 9.0})
        };

        Matrix m(mat);

        // Swap row 0 and row 2
        m.swapElementsByVertical(0, 2);

        // Expected matrix after swap
        std::vector<double> expectedRow0 = { 7.0, 8.0, 9.0 };
        std::vector<double> expectedRow2 = { 1.0, 2.0, 3.0 };

        // Check if rows have been swapped correctly
        assert(m[0][0] == expectedRow0[0] && m[0][1] == expectedRow0[1] && m[0][2] == expectedRow0[2]);
        assert(m[2][0] == expectedRow2[0] && m[2][1] == expectedRow2[1] && m[2][2] == expectedRow2[2]);

        std::cout << "Matrix swapElementsByVertical test passed!" << std::endl;
    }
}

void testGaus() {
    // Test case 1: Simple 3x3 system of equations
    {
        matrixType mat = {
            MathematicalVector({2.0, 1.0, -1.0, 8.0}),   // 2x + y - z = 8
            MathematicalVector({-3.0, -1.0, 2.0, -11.0}), // -3x - y + 2z = -11
            MathematicalVector({-2.0, 1.0, 2.0, -3.0})    // -2x + y + 2z = -3
        };

        Matrix matrix(mat);
        std::vector<type> expectedSolution = { 2.0, 3.0, -1.0 };

        std::vector<type> solution = Gaus(matrix);

        // Check if the solution matches the expected solution
        assert(solution.size() == expectedSolution.size());
        for (size_t i = 0; i < solution.size(); ++i) {
            std::cout << std::fabs(solution[i] - expectedSolution[i]);
            assert(std::fabs(solution[i] - expectedSolution[i]) < 1e-13);  // Check with a tolerance for floating point comparison
        }

        std::cout << "Test 1 passed: Simple 3x3 system of equations solved correctly!" << std::endl;
    }

    // Test case 2: Another 3x3 system
    {
        matrixType mat = {
            MathematicalVector({1.0, 2.0, 0, 5.0}),    // x + 2y = 5
            MathematicalVector({3.0, -1.0, 2.0, 3.0}),    // 3x - y + 2z = 3
            MathematicalVector({2.0, 1.0, 2.0, 6.0})      // 2x + y + 2z = 6
        };

        Matrix matrix(mat);
        std::vector<type> expectedSolution = { 1.0, 2.0, 1.0 };

        std::vector<type> solution = Gaus(matrix);

        // Check if the solution matches the expected solution
        assert(solution.size() == expectedSolution.size());
        for (size_t i = 0; i < solution.size(); ++i) {
            assert(std::fabs(solution[i] - expectedSolution[i]) < 1e-13);  // Check with a tolerance for floating point comparison
        }

        std::cout << "Test 2 passed: Another 3x3 system of equations solved correctly!" << std::endl;
    }

    // Test case 3: Singular matrix (no solution)
    {
        matrixType mat = {
            MathematicalVector({2.0, 1.0, -1.0, 8.0}),   // 2x + y - z = 8
            MathematicalVector({4.0, 2.0, -2.0, 16.0}),  // 4x + 2y - 2z = 16 (duplicate row)
            MathematicalVector({-2.0, 1.0, 2.0, -3.0})   // -2x + y + 2z = -3
        };

        Matrix matrix(mat);

        try {
            std::vector<type> solution = Gaus(matrix);
            // We should not reach here since the matrix is singular
            std::cerr << "Test 3 failed: Singular matrix should throw an exception!" << std::endl;
        }
        catch (...) {
            std::cout << "Test 3 passed: Singular matrix correctly threw exception!" << std::endl;
        }
    }
}
