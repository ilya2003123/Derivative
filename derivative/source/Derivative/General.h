#pragma once

#include <functional>

template<typename F>
class Derivative
{
public:
	Derivative(const F& f, double dx = 1e-6)
		: m_f(f), m_dx(dx)
	{
	}

	double operator()(double x) const
	{
		return ((m_f(x + m_dx) - m_f(x)) / m_dx);
	}

	F m_f;
	double m_dx;


	typedef std::function<double(double)> Type;
	Type expression() const
	{
		return [&](double x)
		{
			return ((m_f(x + m_dx) - m_f(x)) / m_dx);
		};
	}
};