#include <iostream>
#include <ctime>

void Sort(int32_t*, int32_t, int32_t);

int main() {
	try
	{
		int32_t size;
		int32_t* arr;
		std::cout << "Enter length of massive" << "\n";
		std::cin >> size;
		if (size < 1)
			throw "Mistake!";
		srand(time(NULL));
		arr = new int[size];;
		for (int32_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 10 - 5;
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
		Sort(arr, 0, size - 1);
		for (int32_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		delete[] arr;
	}
	catch (const char* str)
	{
		std::cout << str;
	}
	return 0;
}

//быстрая сортировка, Sort(arr, 0, size - 1);
void Sort(int32_t* arr, int32_t start, int32_t end) { //быстрая сортировка
	if (start < end)
	{
		int32_t x = arr[(start + end) / 2];
		int32_t start_1 = start;
		int32_t end_1 = end;
		while (start_1 <= end_1)
		{
			while (arr[start_1] < x) start_1++;
			while (arr[end_1] > x) end_1--;
			if (start_1 <= end_1)
				std::swap(arr[start_1++], arr[end_1--]);
		}
		Sort(arr, start_1, end);
		Sort(arr, start, end_1);
	}

}