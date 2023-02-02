#pragma once

#include "../Functions/functions.h"
#include "../Operations/operations.h"
#include "General.h"
#include "../Utils/Utils.h"

template <typename F1, typename F2>
class Derivative<functions::Logarithm<F1, F2>> : public functions::Abstract
{
public:
	Derivative(const functions::Logarithm<F1, F2>& f)
		: m_f2(f.m_f2), m_factor1(log(f.m_f1)), m_f1(f.m_f1), m_df1(f.m_f1), m_df2(f.m_f2), m_factor2(log(f.m_f2))
	{
	}

	double operator()(double x) override
	{
		double dfx1 = 0;
		double dfx2 = 0;
		double fx1 = 0;
		double fx2 = 0;

		if constexpr (std::is_pointer<Derivative<F1>>::value)
			dfx1 += (*m_df1)(x);
		else
			dfx1 += m_df1(x);

		if constexpr (std::is_pointer<Derivative<F2>>::value)
			dfx2 += (*m_df2)(x);
		else
			dfx2 += m_df2(x);

		if constexpr (std::is_pointer<F1>::value)
			fx1 += (*m_f1)(x);
		else
			fx1 += m_f1(x);

		if constexpr (std::is_pointer<F2>::value)
			fx2 += (*m_f2)(x);
		else
			fx2 += m_f2(x);

		return ((fx1 * dfx2 * m_factor1 - dfx1 * fx2 * m_factor2) / (fx1 * fx2 * m_factor1 * m_factor1));
	}

	double m_factor1;
	double m_factor2;
	F1 m_f1;
	F2 m_f2;
	Derivative<F1> m_df1;
	Derivative<F2> m_df2;

	typedef operations::Divide<operations::Subtract<operations::Multiply<F1,
		operations::Multiply<typename Derivative<F2>::Type, functions::Const>>,
		operations::Multiply<typename Derivative<F1>::Type, operations::Multiply<F2, functions::Const>>>,
		operations::Multiply<F1, operations::Multiply<F2, operations::Multiply<functions::Const,
		functions::Const>>>> Type;
	Type expression() const
	{
		return ((m_f1 * m_df2.expression() * m_factor1 - m_df1.expression() * m_f2 * m_factor2) / 
			(m_f1 * m_f2 * m_factor1 * m_factor1));
	}

};
