#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class Exponent
	{
	public:
		typedef Exponent<F> Type;
		Exponent(double base, const F& f)
			:m_base(base), m_f(f)
		{
		}

		double operator()(double x) const
		{
			return pow(m_base, m_f(x));
		}

		double m_base;
		F m_f;

	};
}