#include "MathematicalVector.h"

MathematicalVector& MathematicalVector::operator-=(const MathematicalVector& right)
{
	for (size_t i = 0; i < this->size(); i++)
	{
		(*this)[i] -= right[i];
	}
    // TODO: вставьте здесь оператор return
    return *this;
}

MathematicalVector::MathematicalVector(std::vector<double> v)
{
	for (auto i : v)
	{
		this->push_back(i);
	}
}

MathematicalVector::MathematicalVector()
{
}

MathematicalVector operator*(const MathematicalVector& left, const double& right)
{
	MathematicalVector v(left);
	for (auto& i : v) {
		i *= right;
	}
	return v;
}
