#pragma once

#include "Abstract.h"
#include <cmath>	
	

namespace functions 
{
	template<typename F1, typename F2>   
	class Logarithm : public functions::Abstract
	{
	public:
		typedef Logarithm<F1, F2> Type;  
		Logarithm(const F1& f1, const F2& f2) 
			:m_f1(f1), m_f2(f2) 
		{   
		}	
	   

		double operator()(double x) override
		{
			double factor = 0;
			double fx = 0;
			if constexpr (std::is_pointer<F2>::value)
				fx = log((*m_f2)(x));
			else
				fx = log(m_f2(x)); 

			if constexpr (std::is_pointer<F1>::value)
				factor = (1. / log((*m_f1)(x)));
			else
				factor = (1. / log(m_f1(x)));

			return fx * factor;
			
		}

		F1 m_f1;
		F2 m_f2;
	};
}