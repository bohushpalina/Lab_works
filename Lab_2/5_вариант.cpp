//Вариант 5
#include <iostream>
#include <cmath>
#include <iomanip>
#include "CountSum.h"

int main()
{
	int32_t k;
	double x;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите x (больше -1 и меньше 1) и k натуральное и больше 1" << '\n';
	std::cin >> x >> k; // к - отрицательная степень 10 для эпсилон
	try
	{
		double result = CountSum(x, k);
		std::cout << "Посчитанное: " << std::setprecision(k) << result << " Из функции: " << std::setprecision(k) << log(x + 1);
	}
	catch (...) { std::cout << "Неверный ввод."; }
	return 0;
}  