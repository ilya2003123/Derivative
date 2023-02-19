#pragma once

#include "General.h"

template <typename F>
typename /*Derivative<F>::Type*/ auto derivative(F f)
{
	return Derivative<F>(f).expression();
}