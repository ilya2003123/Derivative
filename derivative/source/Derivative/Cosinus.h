#pragma once

#include "../Operations/operations.h"
#include "../Functions/functions.h"
#include "General.h"
#include "../Utils/Utils.h"

template <typename F>
class Derivative<functions::Cosinus<F>> 
{
public:
	Derivative(const functions::Cosinus<F>& f)
		: m_f(f.m_f), m_df(f.m_f)
	{
	}

	double operator()(double x) const
	{
		return (-sin(m_f(x)) * m_df(x));
	}

	F m_f;
	Derivative<F> m_df;

	typedef operations::Multiply<operations::Multiply<functions::Const, functions::Sinus<F>>,
		typename Derivative<F>::Type> Type;
	Type expression() const
	{
		return ((functions::Const(-1) * utils::Sin(m_f)) * m_df.expression());
	}
};