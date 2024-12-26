#include <iostream>
#include <ctime>

void Sort(int32_t*, int32_t);

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
		arr = new int[size];
		for (int32_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 10 - 5;
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
		Sort(arr, size);
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

//сортировка вставками, Sort(arr, size);
void Sort(int32_t* arr, int32_t size)
{
	for (int32_t i = 1; i < size; i++) {
		for (int32_t j = i; j > 0; j--) { // Изменено на правильную сортировку вставками
			if (arr[j] < arr[j - 1]) {
				std::swap(arr[j], arr[j - 1]);
			}
			else {
				break; // Если порядок уже правильный, выходим из цикла
			}
		}
	}

}