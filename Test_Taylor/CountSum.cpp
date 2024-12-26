#include <cstdint>
#include <cmath>
#include "CountSum.h"
#include <stdexcept>

double CountSum(double x, int32_t k) {
	if (-1 >= x || 1 < x || k <= 1) // ������ �����
		throw std::invalid_argument("Invalid input values");
	double sum{}, n;
	n = x;            //����� ������������ � ������� ����� ������������������
	int32_t i = 1;
	double e = pow(10, -k);             // � ����� 10 � ������� -�
	while (std::abs(n) >= e) //��������� ������ ����� � �������
	{
		sum += n;
		n = -1 * n * x * i / (i + 1);
		i += 1; //�����������
	}
	return sum;
}