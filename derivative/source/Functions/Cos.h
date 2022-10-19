#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class Cosinus
	{
	public:
		typedef Cosinus<F> Type;
		Cosinus(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return cos(m_f(x));
		}

		F m_f;

	};
}