#pragma once

#include "../Operations/operations.h"
#include "../Functions/functions.h"
#include "General.h"
#include "../Utils/Utils.h"

template <typename F>
class Derivative<functions::Tangent<F>>
{
public:
	Derivative(const functions::Tangent<F>& f)
		: m_f(f.m_f), m_df(f.m_f)
	{
	}

	double operator()(double x) const
	{
		double cosfx = cos(m_f(x));
		return (m_df(x) / (cosfx * cosfx));
	}

	F m_f;
	Derivative<F> m_df;

	typedef operations::Divide<typename Derivative<F>::Type, operations::Multiply<functions::Cosinus<F>,
		functions::Cosinus<F>>> Type;
	Type expression() const
	{
		return (m_df.expression() / (utils::Cos(m_f) * utils::Cos(m_f)));
	}

};