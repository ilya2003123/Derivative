#pragma once

#include "../Operations/operations.h"
#include "../Functions/functions.h"
#include "General.h"

template<typename F1, typename F2>
class Derivative<operations::Add<F1, F2>>
{
public:
	Derivative(const operations::Add<F1, F2>& f)
		: m_df1(f.m_f1), m_df2(f.m_f2)
	{
	}

	double operator()(double x) const
	{
		return m_df1(x) + m_df2;
	}

	Derivative<F1> m_df1;
	Derivative<F2> m_df2;

	typedef operations::Add<typename Derivative<F1>::Type, typename Derivative<F2>::Type> Type;
	Type expression() const
	{
		return m_df1.expression() + m_df2.expression();
	}

};


template<typename F1>
class Derivative<operations::Add<F1, functions::Const>>
{
public:
	Derivative(const operations::Add<F1, functions::Const>& f)
		: m_df1(f.m_f1)
	{
	}

	double operator()(double x) const
	{
		return m_df1(x);
	}

	Derivative<F1> m_df1;

	typedef typename Derivative<F1>::Type Type;
	Type expression() const
	{
		return m_df1.expression();
	}

};

template <typename F2>
class Derivative<operations::Add<functions::Const, F2>> 
{
public:
	Derivative(const operations::Add<functions::Const, F2>& f)
		: m_df2(f.m_f2)
	{
	}
	double operator()(double x) const
	{
		return m_df2(x);
	}
	Derivative<F2> m_df2;
	typedef typename Derivative<F2>::Type Type;
	Type expression() const
	{
		return m_df2.expression();
	}
};

template<>
class Derivative<operations::Add<functions::Const, functions::Const>>
{
public:
	Derivative(const operations::Add<functions::Const, functions::Const>&)
	{
	}

	double operator()(double) const
	{
		return 0;
	}

	typedef typename functions::Const Type;
	Type expression() const
	{
		return functions::Const(0);
	}

};

template <>
class Derivative<operations::Add<functions::Simple, functions::Simple>> 
{
public:
	Derivative(const operations::Add<functions::Simple, functions::Simple>&)
	{
	}

	double operator()(double) const
	{
		return 2;
	}

	typedef functions::Const Type;
	Type expression() const
	{
		return functions::Const(2);
	}
};
