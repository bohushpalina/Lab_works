#include <iostream>
#include <ctime>

int32_t Max(int32_t*, int32_t);
void Sort(int32_t*, int32_t, int32_t*, int32_t);

int main() {
	try
	{
		int32_t size, max;
		int32_t* arr;
		int32_t* arr_1;
		std::cout << "Enter length of massive" << "\n";
		std::cin >> size;
		if (size < 1)
			throw "Mistake!";
		srand(time(NULL));
		arr = new int[size];
		for (int32_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 15;
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
		max = Max(arr, size);
		arr_1 = new int[max + 1] {0};
		Sort(arr, size, arr_1, max);
		for (int32_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		delete[] arr;
		delete[] arr_1;
	}
	catch (const char* str)
	{
		std::cout << str;
	}
	return 0;
}
//подсчетом, Sort(arr, size, arr_1, max);
void Sort(int32_t* arr, int32_t size, int32_t* arr_1, int32_t max) 
//arr_1 создан с размером макс + 1
{
	for (int32_t i = 0; i < size; i++)
		arr_1[arr[i]] += 1;
	int32_t l = 0;
	for (int32_t i = 0; i <= max; i++)
		for (int32_t j = 0; j < arr_1[i]; j++)
			arr[l++] = i;
}

int32_t Max(int32_t* arr, int32_t size) {
	int32_t max = arr[0];
	for (int32_t i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}