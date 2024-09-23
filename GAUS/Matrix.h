#pragma once

#include <vector>
#include "MathematicalVector.h"

using type = double;
using matrixType = std::vector<MathematicalVector>;

struct Matrix
{
	matrixType matrix;
	Matrix(matrixType matrix);
	Matrix(std::vector<std::vector<type>> v);
	void swapElementsByVertical(size_t, size_t);
	size_t size() const;
	MathematicalVector& operator[](size_t);
	std::vector<type> getB(std::vector<type> v) const;
};