#pragma once

#include "../Functions/functions.h"

namespace utils
{
	template<typename F>
	functions::Exponent<F> Exp(double base, const F& f)
	{
		return functions::Exponent<F>(base, f);
	}

	template<typename F>
	functions::Exponent<F> Exp(int base, const F& f)
	{
		return functions::Exponent<F>(base, f);
	}

	double Exp(double base, double x)
	{
		return pow(base, x);
	}


}