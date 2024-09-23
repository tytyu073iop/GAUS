#include "MathematicalVector.h"
#include <cmath>

MathematicalVector& MathematicalVector::operator-=(const MathematicalVector& right)
{
	for (size_t i = 0; i < this->size(); i++)
	{
		(*this)[i] -= right[i];
	}
    // TODO: вставьте здесь оператор return
    return *this;
}

MathematicalVector::MathematicalVector(std::vector<double> v) : std::vector<type>(v)
{

}

MathematicalVector::MathematicalVector()
{

}

type MathematicalVector::Normal() const
{
	// 1
	type sum = 0;
	for (const auto& i : *this) {
		sum += fabs(i);
	}
	return sum;
}

MathematicalVector operator*(const MathematicalVector& left, const double& right)
{
	MathematicalVector v(left);
	for (auto& i : v) {
		i *= right;
	}
	return v;
}

MathematicalVector operator-(const MathematicalVector& left, const MathematicalVector& right)
{
	MathematicalVector c(left);
	for (int i = 0; i < c.size(); i++) {
		c[i] -= right[i];
	}
	return c;
}
