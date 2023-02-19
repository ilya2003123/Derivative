#pragma once

#include <cmath>
#include "Abstract.h"

namespace functions 
{
	template<typename F>  
	class Exponent : public functions::Abstract
	{
	public: 
		typedef Exponent<F> Type;  
		Exponent(const double base, const F& f)
			:m_base(base), m_f(f)
		{
		}

		double operator()(double x) override  
		{
			if constexpr (std::is_pointer<F>::value)
				return pow(m_base, (*m_f)(x));
			else
				return pow(m_base, m_f(x));   
		}								 

		double m_base;  
		F m_f;          

	};
}