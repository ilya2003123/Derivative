#pragma once

#include <assert.h>
#include "../Derivative/derivative.h"
#include "../Functions/functions.h"
#include "../Operations/operations.h"

using namespace utils;

void test()
{

	assert(Sin(0) == 0);
	assert(Cos(0) == 1);
	assert(Pow(2, 2) == 4);
	assert(Exp(2, 4) == 16);
	assert(derivative(Exp(2,X))(1) - 1.38629 <= 1e-5);

	std::cout << "All test done" << std::endl;
}