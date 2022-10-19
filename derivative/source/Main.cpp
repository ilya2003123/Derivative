#include <iostream>
#include "Functions/functions.h"
#include "Operations/operations.h"
#include "Utils/Utils.h"

using namespace utils;

int main() 
{

    extern functions::Simple X;

    auto s = Tg(X) + Sin(X) * Pow(X, 3);

    std::cout << s(1);
    std::cout << std::endl;
    std::cout << s(2);
    std::cout << std::endl;
    std::cout << s(3);
    std::cout << std::endl;
    std::cout << s(4);
    std::cout << std::endl;

    return 0;
}