#pragma once

#include <vector>
#include "MathematicalVector.h"

using type = double;
using matrixType = std::vector<MathematicalVector>;

struct Matrix
{
	matrixType matrix;
	Matrix(matrixType matrix);
	void swapElementsByVertical(size_t, size_t);
	size_t size() const;
	MathematicalVector& operator[](size_t);
};