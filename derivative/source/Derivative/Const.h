#pragma once

#include"../Functions/functions.h"
#include "General.h"

template<>
class Derivative<functions::Const> 
{
public:
	typedef functions::Const Type;
	Derivative(functions::Const) {}

	double operator()(double) const
	{
		return 0;
	}

	Type expression() const
	{
		return functions::Const(0);
	}
};