#pragma once

#include "../Functions/functions.h"
#include "../Operations/operations.h"
#include "General.h"
#include "../Utils/Utils.h"

template <typename F>
class Derivative<functions::Logarithm<F>> 
{
public:
	Derivative(const functions::Logarithm<F>& f)
		: m_base(f.m_base), m_factor(1. / log(m_base)), m_f(f.m_f), m_df(f.m_f)
	{
	}

	double operator()(double x) const
	{
		return (m_factor * m_df(x) / x);
	}

	double m_base, m_factor;
	F m_f;
	Derivative<F> m_df;

	typedef operations::Divide<operations::Multiply<typename Derivative<F>::Type, functions::Const>,
		functions::Simple> Type;
	Type expression() const
	{
		return (m_factor * m_df.expression() / utils::X);
	}

};
