#pragma once

#include "../Functions/functions.h"
#include "../Operations/operations.h"
#include "../Utils/Utils.h"
#include "General.h"

template <typename F1, typename F2>
class Derivative<operations::Divide<F1, F2>>
{
public:
	Derivative(const operations::Divide<F1, F2>& f)
		: m_f1(f.m_f1), m_f2(f.m_f2), m_df1(f.m_f1), m_df2(f.m_f2)
	{
	}

	double operator()(double x) const
	{
		double f2 = m_f2(x);
		return ((m_df1(x) * f2 - m_f1(x) * m_df2(x)) / (f2 * f2));
	}

	F1 m_f1;
	F2 m_f2;
	Derivative<F1> m_df1;
	Derivative<F2> m_df2;

	typedef operations::Multiply<operations::Subtract<operations::Multiply<typename Derivative<F1>::Type, F2>,
		operations::Multiply<F1, typename Derivative<F2>::Type>>, functions::Power<F2>> Type;
	Type expression() const
	{
		return ((m_df1.expression() * m_f2 - m_f1 * m_df2.expression()) * utils::Pow(m_f2, -2));
	}
};

template <typename F2>
class Derivative<operations::Divide<functions::Const, F2>> 
{
public:
	Derivative(const operations::Divide<functions::Const, F2>& f)
		: m_f1(f.m_f1), m_f2(f.m_f2), m_df2(f.m_f2)
	{
	}

	double operator()(double x) const
	{
		double f2 = m_f2(x);
		return (-m_f1.m_const * m_df2(x) / (f2 * f2));
	}

	functions::Const m_f1;
	F2 m_f2;
	Derivative<F2> m_df2;

	typedef operations::Multiply<functions::Const, operations::Multiply<typename Derivative<F2>::Type,
		functions::Power<F2>>> Type;
	Type expression() const
	{
		return (functions::Const(-m_f1.m_const) * (m_df2.expression() * utils::Pow(m_f2, -2)));
	}
};

template <typename F1>
class Derivative<operations::Divide<F1, functions::Const>> 
{
public:
	Derivative(const operations::Divide<F1, functions::Const>& f)
		: m_f2(1 / f.m_f2.m_const), m_df1(f.m_f1)
	{
	}

	double operator()(double x) const
	{
		return m_f2.m_const * m_df1(x);
	}

	functions::Const m_f2;
	Derivative<F1> m_df1;

	typedef operations::Multiply<functions::Const, typename Derivative<F1>::Type> Type;
	Type expression() const
	{
		return (m_f2 * m_df1.expression());
	}
};

template <>
class Derivative<operations::Divide<functions::Const, functions::Const>> 
{
public:
	Derivative(const operations::Divide<functions::Const, functions::Const>& f)
		: m_const(f.m_f1.m_const / f.m_f2.m_const)
	{
	}

	double operator()(double) const
	{
		return 0;
	}

	functions::Const m_const;

	typedef functions::Const Type;
	Type expression() const
	{
		return functions::Const(0);
	}
};