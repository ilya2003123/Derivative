#pragma once

#include "../Operations/operations.h"
#include "../Functions/functions.h"
#include "General.h"
#include "../Utils/Utils.h"

template <typename F>
class Derivative<functions::Cotangent<F>> 
{
public:
	Derivative(const functions::Cotangent<F>& f)
		: m_f(f.m_f), m_df(f.m_f)
	{
	}

	double operator()(double x) const
	{
		double sinfx = sin(m_f(x));
		return (-m_df(x) / (sinfx * sinfx));
	}

	F m_f;
	Derivative<F> m_df;

	typedef operations::Divide<operations::Multiply<functions::Const, typename Derivative<F>::Type>,
		operations::Multiply<functions::Sinus<F>, functions::Sinus<F>>> Type;
	Type expression() const
	{
		return (functions::Const(-1) * m_df.expression() / (utils::Sin(m_f) * utils::Sin(m_f)));
	}

};
