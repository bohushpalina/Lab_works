#include <iostream>
#include <Windows.h>
#include <string>

/*void Bubble_Sort(std::string*&, int32_t*&, int32_t);

int main() {
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int32_t count;
		std::cout << "Введите количество учеников: ";
		std::cin >> count;
		if (count < 1) { throw "Учеников минимум 1 штука!"; }
		std::string* arr_names = new std::string[count];
		int32_t* arr_class = new int32_t[count];
		for (int32_t i = 0; i < count; i++)
		{
			std::cin >> arr_class[i];
			std::cin.ignore();
			std::getline(std::cin, arr_names[i]);
		}
		Bubble_Sort(arr_names, arr_class, count);
		std::cout << "Отсортированный по классам список: " << '\n';
		for (int32_t i = 0; i < count; i++)
		{
			std::cout << arr_class[i] << ' ' << arr_names[i] << '\n';
		}
		
		delete[] arr_names;
		delete[] arr_class;
	}
	catch (const char* str) { std::cout << str; }

	return 0;
}

void Bubble_Sort(std::string*& arr_names, int32_t*& arr_class, int32_t count) {
	for (int32_t i = 0; i < count - 1; i++) {
		for (int32_t j = 0; j < count - i - 1; j++) { // Исправлено условие
			if (arr_class[j] > arr_class[j+1]) {
				std::swap(arr_class[j], arr_class[j+1]);
				std::swap(arr_names[j], arr_names[j + 1]);
			}
		}
	}
} */

//вводится номер класса и имя ребенка программа должна сортировать в порядке возрастания список 

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string first, second;
	std::cout << "Введите две строки для сравнения: ";
	std::getline(std::cin, first, ' ');
	std::getline(std::cin, second);
	if (first < second) { std::cout << first << " выше по алфавиту чем " << second << '\n'; }
	else { std::cout << second << " выше по алфавиту чем " << first << '\n'; }
	if (size(first) > size(second)) { std::cout << first << " больше по количеству символов чем " << second << '\n'; }
	else if (size(first) < size(second)) { std::cout << second << " больше по количеству символов чем " << first << '\n'; }
	else { std::cout << "Оба слова равны по величине)))"; }

	return 0;
}