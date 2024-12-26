#include <cstdint>
#include <cmath>
#include "CountSum.h"
#include <stdexcept>

double CountSum(double x, int32_t k) {
	if (-1 >= x || 1 < x || k <= 1) // Ошибка ввода
		throw std::invalid_argument("Invalid input values");
	double sum{}, n;
	n = x;            //сразу приравниваем к первому члену последовательности
	int32_t i = 1;
	double e = pow(10, -k);             // е равна 10 в степени -к
	while (std::abs(n) >= e) //сравнение модуля числа с эпсилон
	{
		sum += n;
		n = -1 * n * x * i / (i + 1);
		i += 1; //коэффициент
	}
	return sum;
}