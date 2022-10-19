#pragma once

namespace functions
{
	class Const
	{
	public:
		typedef Const Type;
		Const(double x)
			: m_const(x)
		{
		}

		Const(int x)
			: m_const(x)
		{
		}

		double operator()(double) const
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