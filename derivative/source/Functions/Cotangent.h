#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class Cotangent
	{
	public:
		typedef Cotangent<F> Type;
		Cotangent(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return (1 / tan(m_f(x)));
		}

		F m_f;

	};
}