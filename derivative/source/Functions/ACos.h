#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class ACosinus
	{
	public:
		typedef ACosinus<F> Type;
		ACosinus(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return acos(m_f(x));
		}

		F m_f;

	};
}