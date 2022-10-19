#pragma once


namespace operations
{
	template<typename F1, typename F2>
	class Multiply
	{
	public:
		typedef Multiply<F1, F2> Type;
		Multiply(const F1& f1, const F2& f2)
			:m_f1(f1), m_f2(f2)
		{
		}

		double operator()(double x) const
		{
			return m_f1(x) * m_f2(x);
		}

		F1 m_f1;
		F2 m_f2;

	};
}