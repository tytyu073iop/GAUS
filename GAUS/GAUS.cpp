#include "GAUS.h"
#include <stdexcept>
#include <cmath>

std::vector<type> Gaus(Matrix matrix)
{
    auto n = matrix.size();
    // first cycle
	std::vector<size_t> places(n);
	for (size_t i = 0; i < n; i++)
	{
		places[i] = i;
	}
	for (size_t i = 0; i < n; i++)
	{
		// finding max
		size_t maxp = i;
		double max = abs(matrix[i][i]);
		for (size_t j = i + 1; j < n; j++)
		{
			if (max < abs(matrix[j][i]) && matrix[j][i] != 0) {
				maxp = j;
				max = abs(matrix[j][i]);
			}
		}

		//check for zeros
		{
			size_t j = i;
			for (; j < n; j++)
			{
				if (matrix[j][i] != 0) {
					break;
				}
			}
			if (j == n) {
				throw std::runtime_error("cannot solve!");
			}
		}

		// swaping
		std::swap(places[i], places[maxp]);
		matrix.swapElementsByVertical(i, maxp);
		// doing
		for (size_t j = i + 1; j < n; j++)
		{
			type k = matrix[j][i] / matrix[i][i];
			matrix[j] -= matrix[i] * k;
		}
	}
	// done, solwing
	std::vector<type> XSys(n);
	for (long long i = n - 1; i >= 0; i--)
	{
		for (long long j = n - 1; j > i; j--)
		{
			matrix[i][n] -= XSys[j] * matrix[i][j];
		}
		XSys[i] = matrix[i][n] / matrix[i][i];
	}
	for (size_t i = 0; i < n; i++)
	{
		std::swap(XSys[i], XSys[places[i]]);
	}
	return XSys;
}
