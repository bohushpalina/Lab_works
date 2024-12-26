// Написать программу, которая
//18. Находит в последовательности, состоящей из цифр подряд записанных натуральных чисел, цифру с заданным номером.


#include <iostream>
#include <cmath>

int32_t FindDigit(int32_t);
int32_t CountDigits(int32_t);
int32_t CheckDigitsInNumber(int32_t, int32_t, int32_t&, int32_t&);

int main() {
	int32_t input_pos, digit;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите позицию цифры в последовательности натуральных чисел: ";
	std::cin >> input_pos;
	if (input_pos < 1)
		std::cout << "Позиция должна быть натуральным числом";
	else
	{
		digit = FindDigit(input_pos);
		std::cout << "Цифра на данной позиции: " << digit;
		return 0;
	}
	return 0;
}

int32_t FindDigit(int32_t input_pos) {
	int32_t pos = 0;
	int32_t num = 0;
	int32_t deg;
	while (true) // цикл продолжается до тех пор, пока не будет найдена нужная позиция
	{
		num++;
		deg = CountDigits(num);
		std::cout << "Число " << num << '\n';
		int32_t digit = CheckDigitsInNumber(num, deg, pos, input_pos);
		if (digit != - 1)
		{
			return digit; //возвращение цифры прекращает бесконечный цикл
		}
	}
}

int32_t CountDigits(int32_t num) {
	int32_t deg = 1;
	while (num >= pow(10, deg)) //высчитывание цифр в числе
	{
		deg++;
	}
	return deg;
}

int32_t CheckDigitsInNumber(int32_t num, int32_t deg, int32_t& pos, int32_t& input_pos) {
	int32_t digit;
	for (int32_t i = 1; i <= deg; i++)  //цикл для поочередного пересмотря цифры в числе, в зависимости от кол-ва в нем цифр
	{
		digit = (num / static_cast<int32_t>(pow(10, deg - i)));
		if (i != 1)
			digit %= 10; //нахождение по одной цифре за итерацию
		pos += 1;
		std::cout << "Позиция - " << pos << " Цифра - " << digit << '\n'; 
		if (pos == input_pos)
		{
			return digit;
		}
	}
	return -1;
}