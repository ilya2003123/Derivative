#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class Tangent
	{
	public:
		typedef Tangent<F> Type;
		Tangent(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return tan(m_f(x));
		}

		F m_f;

	};
}