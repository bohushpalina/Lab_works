#include <iostream>
#include <string>
#include <windows.h>
// сделать нормально прошлые лабы))
 //сделать так чтобы суммировались целые числа разделенные в строках пробелами и вещественные))

int32_t SumNum(std::string str) {
	int32_t sum = 0;
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
		std::cout << sum + stoi(word) << "..." << word << '\n';
		sum += stoi(word);
		begIndex = str.find_first_not_of(delims, endIndex);
	}
	return sum;
}

int main() {
	std::string str;
	
	int32_t count = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите строку:" << '\n';
	std::getline(std::cin, str);
	std::cout << "Слова:" << '\n';
	std::string::size_type begIndex;
	std::string::size_type endIndex;
	const std::string delims = " ";

	begIndex = str.find_first_not_of(delims);

	while (begIndex != std::string::npos)
	{
		count += 1;
		endIndex = str.find_first_of(delims, begIndex);
		if (endIndex == std::string::npos)
			endIndex = str.length();
		std::string word = str.substr(begIndex, endIndex - begIndex);
		std::cout << count << ". " << word << '\n';
		begIndex = str.find_first_not_of(delims,  endIndex);
	}

	int32_t sum = SumNum(str);
	

	return 0;
}