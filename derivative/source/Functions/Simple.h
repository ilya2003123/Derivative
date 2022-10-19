#pragma once

namespace functions
{
	class Simple
	{
	public:
		typedef Simple Type;

		double operator()(double x) const
		{
			return x;
		}
	};
}