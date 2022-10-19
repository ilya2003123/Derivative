#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class Sinus
	{
	public:
		typedef Sinus<F> Type;
		Sinus(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return sin(m_f(x));
		}

		F m_f;

	};
}