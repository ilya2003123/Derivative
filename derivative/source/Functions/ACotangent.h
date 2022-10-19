#pragma once

#include <cmath>

namespace functions
{
	template<typename F>
	class ACotangent
	{
		typedef ACotangent<F> Type;
		ACotangent(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) const
		{
			return (1 / atan(m_f(x)));
		}

		F m_f;

	};
}