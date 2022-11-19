#pragma warning(disable: 26451)

#include <iostream>
#include <string>
#include <vector>
#include "Functions/functions.h"
#include "Operations/operations.h"
#include "Utils/Utils.h"
#include "Derivative/derivative.h"
#include "Parser/Parser.h"
//#include <iomanip> - для вывода, можно отрегулировать сколько знаков после запятой выводится!

#define e 2.718281  // постоянные переменные, обязательно пригодятся
#define pi 3.141592

using namespace utils;  // Просто потому что надо! :D


int main() 
{
	try
	{
		std::string str;
		std::cout << "Function: ";
		std::cin >> str;
		std::cout << std::endl;
		std::cout << "X: ";
		std::cin >> inputx;
		std::cout << std::endl;

		Parser p(str.c_str());
		auto q = p.parse();
		auto result = eval(q);
		std::cout << result << std::endl;
	}
	catch (std::runtime_error& Error) { std::cout << Error.what() << std::endl; }

	//auto u = X;

	//auto uu = Tg(X);
	//std::cout << uu(1) << std::endl;   

	//auto v = Sin(X);    

	//auto acos = ACos(u) + u;

	//std::cout << acos(1) << std::endl;

	//auto sub = uu - v;
	//std::cout << sub(1) << std::endl;

	//auto div = uu / v;
	//std::cout << div(1) << std::endl;

	//auto mul = uu * v;
	//std::cout << mul(1) << std::endl;

	//auto q2 = Sin(u);
	//
	//auto q = Sin(q2) + v;
	//
	///*std::cout << (*q).eval(5);*/
	//
	//auto sumsa = q + Sin(X);
	//
	//std::cout << sumsa(1) << std::endl;

	//auto dq = derivative(q); 
	//std::cout << dq(1) << std::endl;

	return 0;
}