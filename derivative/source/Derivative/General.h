#pragma once

#include <functional>  



template<typename F> 
class Derivative : public functions::Abstract
{
public:
	Derivative(const F& f, double dx = 5e-6)
		: m_f(f), m_dx(dx)
	{
	}

	double operator()(double x) override
	{
		double fx1 = 0;
		double fx2 = 0;

		if constexpr (std::is_pointer<F>::value)
			fx1 += (*m_f)(x + m_dx);
		else
			fx1 += m_f(x + m_dx);

		if constexpr (std::is_pointer<F>::value)
			fx2 += (*m_f)(x);
		else
			fx2 += m_f(x);

		return ((fx1 - fx2) / m_dx);
	}

	F m_f;
	double m_dx;


	typedef std::function<double(double)> Type;
	Type expression()
	{
		return [&](double x)
		{
			return ((m_f(x + m_dx) - m_f(x)) / m_dx);
		};
	}
};