#pragma once

#include "Abstract.h"

namespace functions   
{					 
	class Const : public functions::Abstract
	{
	public:
		typedef Const Type;  
		Const(const double x)  
			: m_const(x)
		{
		}

		Const(const int x)   
			: m_const(x)
		{
		}

		double operator()(double) override 
		{                               
			return m_const;
		}                                
		                               

		operator double() 
		{                  
			return m_const;
		}

		double m_const;  
	};

}