#pragma once
#include <vector>

using type = double;

struct MathematicalVector: public std::vector<double> {
	MathematicalVector& operator-=(const MathematicalVector& right);
	MathematicalVector(std::vector<double>);
	MathematicalVector();
	type Normal() const;
};

MathematicalVector operator*(const MathematicalVector& left,const double& right);
MathematicalVector operator-(const MathematicalVector& left, const MathematicalVector& right);