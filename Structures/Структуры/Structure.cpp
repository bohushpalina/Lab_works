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
	book lib_1; //��� ���������������� ���������� ��������� � �������� ���������!
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "������� �������� �����: ";
	std::getline(std::cin, lib_1.name);
	std::cout << "������� ������ �����: ";
	std::getline(std::cin, lib_1.author);
	std::cout << "������� ���-�� ������� �  �����: ";
	std::cin >> lib_1.pages;
	std::cout << "������� ��������� �����: ";
	std::cin >> lib_1.cost;
	std::cout << lib_1.name << " " << lib_1.author << " " << lib_1.pages << " " << lib_1.cost;
	return 0;
}