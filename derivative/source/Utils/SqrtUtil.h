#pragma once

#include "../Functions/functions.h"

namespace utils
{
	template<typename F>
	functions::Power<F> Sqrt(const F& f)
	{
		return functions::Power<F>(f, 0.5);
	}

	double Sqrt(double x)
	{
		return sqrt(x);
	}

}