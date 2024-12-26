#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

void CheckFile(std::ifstream& file)
{
	if (!file)
		throw std::invalid_argument("Файл не существует");
	if (!file.is_open())
		throw std::invalid_argument("Файл не открылся");
	if (file.peek() == EOF)
		throw std::invalid_argument("Файл пуст");
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file("Input.txt");
	CheckFile(file);
	std::string string, word;
	int32_t Begind, Endind;
	std::string delims = ":;";
	int32_t counter = 0;

	//
	while (std::getline(file, string))
	{
		Begind = string.find_first_not_of(delims);
		counter = 0;
		while (Begind != std::string::npos)
		{
			counter++;
			Endind = string.find_first_of(delims, Begind);
			if (Endind == std::string::npos)
				Endind = string.size();
			word = string.substr(Begind, Endind - Begind);
			if (counter == 2)
			{
				std::cout << word.substr(1, word.size() - 1) << '\n';
			}
			if (counter == 1)
			{
				std::cout << word << '\n';
			}
			if (counter == 3)
			{
				/*Begind = word.find_first_not_of("-");
				Endind = word.find_first_of("-");*/
				std::cout << std::stoi(word.substr(word.find_first_not_of("-") + 1, word.find_first_of("-") - 1)) << '\n';
				//Begind = word.find_first_not_of("-", word.find_first_of("-"));
				//Endind = word.size();
				std::cout << std::stoi(word.substr(word.find_first_not_of("-", word.find_first_of("-")) + 1, word.size() -word.find_first_not_of("-", word.find_first_of("-")))) << '\n';
			}
			Begind = Begind = string.find_first_not_of(delims, Endind);
		}
	}
	file.close();
	return 0;
}
