#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class ATangent
	{
	public:
		typedef ATangent<F> Type;
		ATangent(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return atan(m_f(x));
		}

		F m_f;

	};
}