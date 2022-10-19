#pragma once

#include "../Functions/functions.h"

namespace utils
{
	template<typename F>
	functions::Logarithm<F> Log(double base, const F& f)
	{
		return functions::Logarithm<F>(base, f);
	}

	template<typename F>
	functions::Logarithm<F> Log(int base, const F& f)
	{
		return functions::Logarithm<F>(base, f);
	}

	double Log(double base, double x)
	{
		return (log(x) / log(base));
	}


}