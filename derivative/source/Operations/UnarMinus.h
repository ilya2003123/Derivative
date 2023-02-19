#pragma once

#include "../Functions/Abstract.h"

namespace operations  
{
	template<typename F>
	class UnarMinus : public functions::Abstract
	{
	public:
		typedef UnarMinus<F> Type;  
		UnarMinus(const F& f)  
			:m_f(f)
		{
		}

		double operator()(double x) override  
		{
			double f = 0;

			if constexpr (std::is_pointer<F>::value)
				f += (*m_f)(x);
			else
				f += m_f(x);

			return -f;
		}

		F m_f; 

	};
}