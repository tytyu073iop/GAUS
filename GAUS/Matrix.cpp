#include "Matrix.h"

Matrix::Matrix(matrixType matrix) : matrix(matrix)
{

}

void Matrix::swapElementsByVertical(size_t a, size_t b)
{
	std::swap(matrix[a], matrix[b]);
}

size_t Matrix::size() const
{
	return matrix.size();
}

MathematicalVector& Matrix::operator[](size_t i)
{
	return matrix[i];
}
