#pragma once

#include "../Functions/functions.h"
#include "../Operations/operations.h"
#include "../Utils/Utils.h"
#include "General.h"


template <typename F>
class Derivative<functions::Sinus<F>> 
{
public:
	Derivative(const functions::Sinus<F>& f)
		: m_f(f.m_f), m_df(f.m_f)
	{
	}

	double operator()(double x) const
	{
		return (cos(m_f(x)) * m_df(x));
	}

	F m_f;
	Derivative<F> m_df;

	typedef operations::Multiply<functions::Cosinus<F>, typename Derivative<F>::Type> Type;
	Type expression() const
	{
		return (utils::Cos(m_f) * m_df.expression());
	}

};
