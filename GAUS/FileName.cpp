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
    auto B = A.getB(X);

    //creating new matrix and connecting for gaus
    auto gaus = A;
    for (int i = 0; i < n; i++)
    {
        gaus[i].push_back(B[i]);
    }

    //gaus
    auto solve = Gaus(gaus);

    //printing
    {
        const int q = 5;
        std::cout << "presize:\n";
        for (int i = 0; i < q; i++)
        {
            std::cout << X[i] << " ";
        }
        for (int i = 1; i <= q; i++)
        {
            std::cout << X[(n - i)] << " ";
        }
        std::cout << "\nnot:\n";
        std::cout << "presize:\n";
        for (int i = 0; i < q; i++)
        {
            std::cout << solve[i] << " ";
        }
        for (int i = 1; i <= q; i++)
        {
            std::cout << solve[(n - i)] << " ";
        }
    }

    return 0;
}
