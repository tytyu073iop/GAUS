#include <iostream>
#include <vector>
#include <cassert>
#include "MathematicalVector.h"
#include "Matrix.h"// Include your header file
#include "GAUS.h"
#include <cstdlib>
#include <ctime>
#include "Tests.h"


int main() {
    // Run the test function
    testMathematicalVector();
    testMatrix();
    testGaus();

    // Random
    srand(time(NULL)); 

    //creating
    const int n = 1000;
    std::vector<std::vector<type>> a(n, std::vector<type>(n));

    //filling
    for (auto& i : a) {
        for (auto& j : i) {
            j = (rand() % 200) - 100;
        }
    }

    //
    Matrix A(a);

    //creating solution
    std::vector<type> X(n);

    //filling solution
    const int m = 1;
    for (int i = 0; i < n; i++)
    {
        X[i] = m + i;
    }

    //creating b
    auto b = A.getB(X);

    return 0;
}
