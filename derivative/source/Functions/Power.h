#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class Power
	{
	public:
		typedef Power<F> Type;
		Power(const F& f, double n)
			: m_f(f), m_n(n)
		{
		}

		double operator()(double x) const
		{
			return pow(m_f(x), m_n);
		}

		F m_f;
		double m_n;

	};
}