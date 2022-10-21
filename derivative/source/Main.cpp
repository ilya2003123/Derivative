#include <iostream>
#include "Functions/functions.h"
#include "Operations/operations.h"
#include "Utils/Utils.h"
#include "Derivative/derivative.h"

#define e 2.718281 
#define pi 3.141592

using namespace utils;

int main() 
{

    auto s = (Tg(X + 1) + Sin(X) + Sqrt(X) + Log(e, X) * Pow(X, 3) * Log(pi, Pow(X, 3)));


    const auto ds = derivative(s);

    std::cout << s(1);
    std::cout << std::endl;
    std::cout << ds(1);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << s(2);
    std::cout << std::endl;
    std::cout << ds(2);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << s(3);
    std::cout << std::endl;
    std::cout << ds(3);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << s(4);
    std::cout << std::endl;
    std::cout << ds(4);
    std::cout << std::endl;

    return 0;
}