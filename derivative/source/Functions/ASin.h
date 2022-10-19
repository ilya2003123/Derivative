#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class ASinus
	{
	public:
		typedef ASinus<F> Type;
		ASinus(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return asin(m_f(x));
		}

		F m_f;

	};
}