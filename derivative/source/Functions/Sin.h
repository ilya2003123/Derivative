#pragma once

#include <cmath>
#include "Abstract.h"

namespace functions  
{                    
	template<typename F>
	class Sinus : public functions::Abstract
	{
	public:
		typedef Sinus<F> Type;
		Sinus(const F& f)
			:m_f(f)
		{
		}

		double operator()(double x) override
		{
			if constexpr (std::is_pointer<F>::value)
				return sin((*m_f)(x));
			else
				return sin(m_f(x));
		}

		F m_f;

	};
}