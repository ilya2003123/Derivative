#pragma once

#include"../Functions/functions.h"
#include "General.h"

template<>
class Derivative<functions::Simple>
{
public:
	typedef functions::Const Type;
	Derivative(functions::Simple) {}

	double operator()(double)
	{
		return 1;
	}

	Type expression() const
	{
		return functions::Const(1);
	}

};