#include "Matrix.h"

Matrix::Matrix(matrixType matrix) : matrix(matrix)
{

}

Matrix::Matrix(std::vector<std::vector<type>> v)
{
	matrix = std::vector<MathematicalVector>();
	for (auto i : v) {
		matrix.push_back(i);
	}
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

std::vector<type> Matrix::getB(std::vector<type> v) const
{
	std::vector<type> n(v.size());
	for (int i = 0; i < v.size(); i++)
	{
		type sum = 0;
		for (int j = 0; j < v.size(); j++)
		{
			sum += matrix[i][j] * v[j];
		}
		n[i] = sum;
	}
	return n;
}
