//������� 5
#include <iostream>
#include <cmath>
#include <iomanip>
#include "CountSum.h"

int main()
{
	int32_t k;
	double x;
	setlocale(LC_ALL, "Russian");
	std::cout << "������� x (������ -1 � ������ 1) � k ����������� � ������ 1" << '\n';
	std::cin >> x >> k; // � - ������������� ������� 10 ��� �������
	try
	{
		double result = CountSum(x, k);
		std::cout << "�����������: " << std::setprecision(k) << result << " �� �������: " << std::setprecision(k) << log(x + 1);
	}
	catch (...) { std::cout << "�������� ����."; }
	return 0;
}  