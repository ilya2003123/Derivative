#pragma once

#include "../Functions/functions.h"
#include "../Operations/operations.h"
#include "General.h"
#include "../Utils/Utils.h"

template <class F>
class Derivative<functions::Power<F>> 
{
public:
	Derivative(const functions::Power<F>& f)
		: m_f(f.m_f), m_n(f.m_n), m_df(f.m_f)
	{
	}

	double operator()(double x) const
	{
		return (m_n * pow(m_f(x), m_n - 1) * m_df(x));
	}

	F m_f;
	double m_n;
	Derivative<F> m_df;

	typedef operations::Multiply<operations::Multiply<functions::Const, functions::Power<F> >,
		typename Derivative<F>::Type> Type;
	Type expression() const
	{
		return ((functions::Const(m_n) * utils::Pow(m_f, m_n - 1)) * m_df.expression());
	}

};

template <>
class Derivative<functions::Power<functions::Const>> 
{
public:
	Derivative(const functions::Power<functions::Const>& )
	{
	}

	double operator()(double) const
	{
		return 0;
	}

	typedef functions::Const Type;
	Type expression() const
	{
		return functions::Const(0);
	}
};

template <>
class Derivative<functions::Power<functions::Simple>> 
{
public:
	Derivative(const functions::Power<functions::Simple>& f)
		: m_n(f.m_n)
	{
	}

	double operator()(double x) const
	{
		return (m_n * pow(x, m_n - 1));
	}

	double m_n;


	typedef operations::Multiply<functions::Const, functions::Power<functions::Simple>> Type;
	Type expression() const
	{
		return operations::Multiply<functions::Const, functions::Power<functions::Simple>>
			(functions::Const(m_n), utils::Pow(utils::X, m_n - 1));
	}

};