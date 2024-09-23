#include <iostream>
#include <vector>
#include <cassert>
#include "MathematicalVector.h"
#include "Matrix.h"// Include your header file
#include "GAUS.h"
#include <cstdlib>
#include <ctime>
#include "Tests.h"

void task1() {

    // Random
    auto begin = time(NULL);
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
        for (int i = n - q - 1; i < n; i++)
        {
            std::cout << X[i] << " ";
        }
        std::cout << "\nnot:\n";
        for (int i = 0; i < q; i++)
        {
            std::cout << solve[i] << " ";
        }
        for (int i = n - q - 1; i < n; i++)
        {
            std::cout << solve[i] << " ";
        }
    }

    // pogrsnost
    std::cout << "\npogrestnost: " << ((X - MathematicalVector(solve)).Normal() / (MathematicalVector(X).Normal()));

    //counting
    std::cout << "\ntime: " << time(NULL) - begin << " s\n";
}

void task2() {

    auto begin = time(NULL);

    //creating
    const int n = 10;
    std::vector<std::vector<type>> a(n, std::vector<type>(n));

    //filling
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1.0 / (i + j + 2 - 1);
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
        X[i] = i + 1;
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
        const int q = 10;
        std::cout << "presize:\n";
        for (int i = 0; i < q; i++)
        {
            std::cout << X[i] << " ";
        }
        std::cout << "\nnot:\n";
        for (int i = 0; i < q; i++)
        {
            std::cout << solve[i] << " ";
        }
    }

    // pogrsnost
    std::cout << "\npogrestnost: " << ((X - MathematicalVector(solve)).Normal() / (MathematicalVector(X).Normal()));

    //counting
    std::cout << "\ntime: " << time(NULL) - begin << " s\n";
}


int main() {
    // Run the test function
    testMathematicalVector();
    testMatrix();
    testGaus();

    task1();
    task2();

    return 0;
}
