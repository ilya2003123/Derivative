#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class Logarithm
	{
	public:
		typedef Logarithm<F> Type;
		Logarithm(double base, const F& f)
			:m_base(base), m_factor(1. / log(base)), m_f(f)
		{
		}

		double operator()(double x) const
		{
			return log(m_f(x)) * m_factor;
		}

		double m_base, m_factor;
		F m_f;

	};
}