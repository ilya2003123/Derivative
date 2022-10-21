#pragma once

#include "../Functions/functions.h"
#include "../Operations/operations.h"
#include "General.h"

template<typename F1, typename F2>
class Derivative<operations::Multiply<F1, F2>>
{
public:
	Derivative(const operations::Multiply<F1, F2>& f)
		: m_df1(f.m_f1), m_df2(f.m_f2), m_f1(f.m_f1), m_f2(f.m_f2)
	{
	}

	double operator()(double x) const
	{
		return ((m_df1(x) * m_f2(x)) + (m_f1(x) * m_df2(x)));
	}

	Derivative<F1> m_df1;
	Derivative<F2> m_df2;
	F1 m_f1;
	F2 m_f2;

	typedef operations::Add<operations::Multiply<typename Derivative<F1>::Type, F2>,
		operations::Multiply<F1, typename Derivative <F2>::Type>> Type;
	Type expression() const
	{
		return ((m_df1.expression() * m_f2) + (m_f1 * m_df2.expression()));
	}

};


template<typename F1>
class Derivative<operations::Multiply<F1, functions::Const>>
{
public:
	Derivative(const operations::Multiply<F1, functions::Const>& f)
		: m_df1(f.m_f1), m_f2(f.m_f2)
	{
	}

	double operator()(double x) const
	{
		return (m_df1(x) * m_f2.m_const);
	}

	Derivative<F1> m_df1;
	functions::Const m_f2;

	typedef operations::Multiply<functions::Const, typename Derivative<F1>::Type> Type;
	Type expression() const
	{
		return (m_f2 * m_df1.expression());
	}

};

template<typename F2>
class Derivative<operations::Multiply<functions::Const, F2>>
{
public:

	Derivative(const operations::Multiply<functions::Const, F2>& f)
		: m_f1(f.m_f1), m_df2(f.m_f2)
	{
	}

	double operator()(double x) const
	{
		return (m_f1.m_const * m_df2(x));
	}


	functions::Const m_f1;
	Derivative<F2> m_df2;

	typedef operations::Multiply<functions::Const, typename Derivative<F2>::Type> Type;
	Type expression() const
	{
		return (m_f1 * m_df2.expression());
	}

};

template<>
class Derivative<operations::Multiply<functions::Const, functions::Const>>
{
public:
	Derivative(const operations::Multiply<functions::Const, functions::Const>&)
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