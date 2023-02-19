#pragma once

#include "Abstract.h"

namespace functions  
{
	class Simple : public functions::Abstract
	{
	public:
		typedef Simple Type;   

		double operator()(double x) override  
		{                                
			return x;
		}
	};
}