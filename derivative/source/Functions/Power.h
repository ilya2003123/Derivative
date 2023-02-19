#pragma once

#include <cmath>
#include "Abstract.h"

namespace functions  
{
	template<typename F> 
	class Power : public functions::Abstract
	{
	public:  
		typedef Power<F> Type;  
		Power(const F& f, const double n)   
			: m_f(f), m_n(n)
		{
		}

		double operator()(double x) override  
		{
			if constexpr (std::is_pointer<F>::value)
				return pow((*m_f)(x), m_n);
			else
				return pow(m_f(x), m_n);
		}

		F m_f;        
		double m_n;   

	};
}