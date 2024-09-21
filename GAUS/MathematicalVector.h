#pragma once
#include <vector>

struct MathematicalVector: public std::vector<double> {
	MathematicalVector& operator-=(const MathematicalVector& right);
	MathematicalVector(std::vector<double>);
	MathematicalVector();
};

MathematicalVector operator*(const MathematicalVector& left,const double& right);