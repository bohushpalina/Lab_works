#include <iostream>
#include <string>
#include <windows.h>

float FindNumb(std::string word, bool& ex) {
	std::string number = {};
	for (int32_t i = 0; i < word.length(); i++)
	{
		if ((word[i] >= '0' && word[i] <= '9') || (word[i] == '-' && number.length() == 0) || (word[i] == '.' && (number.length() != 0 && number[number.length() - 1] != '.') && (number.length() >= 2 || (number.length() == 1 && number[0] != '-'))))
			number = number + word[i];
	}
	if (number.length() != 0)
	{
		ex = 1;
		return stof(number);
	}
	else
		return 0;
}




void ChooseWords(std::string str, float& sum, bool& ex) {
	std::string word;
	std::string::size_type begIndex;
	std::string::size_type endIndex;
	const std::string delims = " ";
	begIndex = str.find_first_not_of(delims);
	while (begIndex != std::string::npos)
	{
		endIndex = str.find_first_of(delims, begIndex);
		if (endIndex == std::string::npos)
			endIndex = str.length();
		word = str.substr(begIndex, endIndex - begIndex);
		sum += FindNumb(word, ex);
		begIndex = str.find_first_not_of(delims, endIndex);
	}
}

int main() {
	float sum = 0;
	bool ex = 0;
	std::string str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите строку:" << '\n';
	std::getline(std::cin, str);
	ChooseWords(str, sum, ex);
	if (ex)
	{
		std::cout << "Сумма вещественных чисел: " << sum;
	}
	else
		std::cout << "В строке нет чисел";
	return 0;
}