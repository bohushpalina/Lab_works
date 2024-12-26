//В целочисленной квадратной матрице найти:
//-максимальный элемент в тех столбцах, которые не содержат положительных элементов;
//-подсчитать количество отрицательных элементов в нижнем правом
// треугольнике квадратной матрицы, включая диагональ.

#include <iostream>
#include <ctime>
#include <iomanip>

void EnterVariant(int32_t&);
void DeleteArray(int32_t**&, int32_t);
void AllocateArray(int32_t**&, int32_t);
void InputSize(int32_t&);
void CheckSize(int32_t);
void InputMinMax(int32_t&, int32_t&);
void InputArray(int32_t**&, int32_t);
void GenerateArray(int32_t**&, int32_t, int32_t, int32_t);
void FindMax(int32_t**&, int32_t, int32_t&, bool&);
void CheckMax(bool);
void OutputVar(int32_t);
void OutputArray(int32_t**, int32_t);
void CountTriangle(int32_t**, int32_t, int32_t&);

int main() {
	int32_t** arr = nullptr;
	int32_t size;
	try 
	{
		int32_t var;
		setlocale(LC_ALL, "Russian");
		InputSize(size);
		CheckSize(size);
		AllocateArray(arr, size); 
		EnterVariant(var);
		switch (var)
		{
		case 1: 
			srand(time(NULL));
			int32_t min_enter, max_enter;
			InputMinMax(min_enter, max_enter);
			GenerateArray(arr, size, min_enter, max_enter);
			std::cout << "Сгенерированная матрица: " << '\n';
			OutputArray(arr, size);
			break;
		case 2:
			InputArray(arr, size);
			break;
		default: throw "Неверный ввод!";
		}
		try {
			int32_t max;
			bool exist = 0;
			FindMax(arr, size, max, exist);
			CheckMax(exist);
			std::cout << "Максимальное число в неположительных столбцах матрицы: ";
			OutputVar(max);
		}
		catch (const char* str) { std::cout << str << '\n'; }
		int32_t count = 0;
		CountTriangle(arr, size, count);
		std::cout << "Количество отрицательных элементов в нижнем правом треугольнике: ";
		OutputVar(count);
	}
	catch (const char* str) { std::cout << str; }
	DeleteArray(arr, size);
	return 0;
}

void InputSize(int32_t& size) {
	std::cout << "Введите размер n (n * n) матрицы: ";
	std::cin >> size;
}

void CheckSize(int32_t size) {
	if (size < 1)
	{
		throw "Размер должен быть положительным!";
	}
}

void AllocateArray(int32_t**& arr, int32_t size) {
	arr = new int32_t * [size];
	for (int32_t i = 0; i < size; i++)
	{
		arr[i] = new int32_t[size];
	}
}

void DeleteArray(int32_t**& arr, int32_t size) {
	for (int32_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void EnterVariant(int32_t& var) {
	std::cout << "Сгенерировать двумерный массив (ввод 1) или ввести вручную (ввод 2): ";
	std::cin >> var;
}

void InputMinMax(int32_t& min, int32_t& max) {
	std::cout << "Введите минимальное и максимальное значения для элементов в двумерном массиве: ";
	std::cin >> min >> max;
	if (min > max) { std::swap(min, max); }
}

void InputArray(int32_t**& arr, int32_t size) {
	std::cout << "Введите двумерный массив: " << '\n';
	for (int32_t i = 0; i < size; i++)
		for (int32_t j = 0; j < size; j++)
			std::cin >> arr[i][j];
}

void GenerateArray(int32_t**& arr, int32_t size, int32_t min, int32_t max) {
	for (int32_t i = 0; i < size; i++)
	{
		for (int32_t j = 0; j < size; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

void FindMax(int32_t**& arr, int32_t size, int32_t& Max, bool& exist) {
	int max, ex; //внутренние переменные
	Max = arr[0][0]; //внешняя переменная 
	for (int32_t i = 0; i < size; i++)
	{
		max = arr[0][i];
		ex = 1;
		for (int32_t j = 0; j < size; j++) 
		{
			if (ex && arr[j][i] > 0) //проверяем столбец на неположительность
			{
				ex = 0;
			}
			else if (ex && arr[j][i] > max) //наибольший приравниваем к максу
			{
				max = arr[j][i];
			}
		}
		if (ex && max >= Max)
		{
			Max = max;
			exist = 1;
		}
	}
}

void CheckMax(bool ex) {
	if (ex == 0)
		throw "Отсутствуют столбцы с неположительными элементами!";
}

void OutputVar(int32_t var) {
	std::cout << var << '\n';
}

void OutputArray(int32_t** arr, int32_t size) {
	for (int32_t i = 0; i < size; i++)
	{
		for (int32_t j = 0; j < size; j++)
			std::cout << std::setw(4) << arr[i][j] << " ";
		std::cout << '\n';
	}
}

void CountTriangle(int32_t** arr, int32_t size, int32_t& count) {
	for (int32_t j = 0; j < size; j++)
	{
		for (int32_t i = size - 1 - j; i < size;  i++)
		{
			if (arr[i][j] < 0)
				count += 1;
		}
	}
}