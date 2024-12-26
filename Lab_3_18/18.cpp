// �������� ���������, �������
//18. ������� � ������������������, ��������� �� ���� ������ ���������� ����������� �����, ����� � �������� �������.


#include <iostream>
#include <cmath>

int32_t FindDigit(int32_t);
int32_t CountDigits(int32_t);
int32_t CheckDigitsInNumber(int32_t, int32_t, int32_t&, int32_t&);

int main() {
	int32_t input_pos, digit;
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ������� ����� � ������������������ ����������� �����: ";
	std::cin >> input_pos;
	if (input_pos < 1)
		std::cout << "������� ������ ���� ����������� ������";
	else
	{
		digit = FindDigit(input_pos);
		std::cout << "����� �� ������ �������: " << digit;
		return 0;
	}
	return 0;
}

int32_t FindDigit(int32_t input_pos) {
	int32_t pos = 0;
	int32_t num = 0;
	int32_t deg;
	while (true) // ���� ������������ �� ��� ���, ���� �� ����� ������� ������ �������
	{
		num++;
		deg = CountDigits(num);
		std::cout << "����� " << num << '\n';
		int32_t digit = CheckDigitsInNumber(num, deg, pos, input_pos);
		if (digit != - 1)
		{
			return digit; //����������� ����� ���������� ����������� ����
		}
	}
}

int32_t CountDigits(int32_t num) {
	int32_t deg = 1;
	while (num >= pow(10, deg)) //������������ ���� � �����
	{
		deg++;
	}
	return deg;
}

int32_t CheckDigitsInNumber(int32_t num, int32_t deg, int32_t& pos, int32_t& input_pos) {
	int32_t digit;
	for (int32_t i = 1; i <= deg; i++)  //���� ��� ������������ ���������� ����� � �����, � ����������� �� ���-�� � ��� ����
	{
		digit = (num / static_cast<int32_t>(pow(10, deg - i)));
		if (i != 1)
			digit %= 10; //���������� �� ����� ����� �� ��������
		pos += 1;
		std::cout << "������� - " << pos << " ����� - " << digit << '\n'; 
		if (pos == input_pos)
		{
			return digit;
		}
	}
	return -1;
}