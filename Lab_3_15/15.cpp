#include <iostream>
#include <cmath>

//�������� ���������, ������� �� �������� �������[a, b] ������������ ���� ����� �������
// �����, ���������� ������ ������� ���� ������ ������������ ������������������ ����


bool CheckNumber(int64_t);

int main() {
	bool ex = 0;
	int32_t min, max;
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ����� � ������ ������� ���������� ������������� �����: ";
	std::cin >> min >> max;
	if (min > max)
		std::swap(min, max);
	if (min < 1 || max < 1 || min == max)
		std::cout << "����� ������ ���� ������������ � ��������!";
	else
	{
		std::cout << "�����, ���������� ������ ������� ���� ������ ������������ ������������������ ����: ";
		for (int32_t num = min; num <= max; num++)
		{
			if (CheckNumber(num))
			{
				std::cout << '\n' << num;
				ex = 1;
			}
			
		}
		if (!ex)
			std::cout << "---" << '\n' << "����� ����� �� ���������� �� ������ ����������";
	}

	return 0;
}


bool CheckNumber(int64_t num) { //���������������� �������� �� ��, �������� �� ����������� ����� ������ ����������
	int32_t digit;
	int64_t num_copy = num;
	while (num / 10 > 0)
	{
		digit = num % 10;
		if (num / 10 % 10 >= digit)
			return 0;
		num /= 10;
	}
	return 1;
}