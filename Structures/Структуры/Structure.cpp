#include <iostream>
#include <string>
#include <Windows.h>

int main() {
	struct book
	{
		std::string name;
		std::string author;
		int32_t pages;
		double cost;
	};
	book lib_1; //тип пользовательской переменной совпадает с название структуры!
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "¬ведите название книги: ";
	std::getline(std::cin, lib_1.name);
	std::cout << "¬ведите автора книги: ";
	std::getline(std::cin, lib_1.author);
	std::cout << "¬ведите кол-во страниц в  книге: ";
	std::cin >> lib_1.pages;
	std::cout << "¬ведите стоимость книги: ";
	std::cin >> lib_1.cost;
	std::cout << lib_1.name << " " << lib_1.author << " " << lib_1.pages << " " << lib_1.cost;
	return 0;
}