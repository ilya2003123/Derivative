#pragma once

#include "General.h"

template <typename F>
typename Derivative<F>::Type derivative(F f)
{
	return Derivative<F>(f).expression();
}