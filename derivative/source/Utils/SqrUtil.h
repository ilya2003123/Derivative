#pragma once

#include "../Operations/operations.h"

namespace utils
{
	template<typename F>
	operations::Multiply<F, F> Sqr(F& f)
	{
		return operations::Multiply<F, F>(f, f);
	}

	double Sqr(double x) 
	{
		return x * x;
	}

}