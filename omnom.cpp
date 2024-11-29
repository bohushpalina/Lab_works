#include <iostream>

void Output_array(int32_t* arr, int32_t size) {
	std::cout << "Вывод отсортированного массива: ";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

}

bool Check_size(int32_t size, int32_t max) {
	if (size > max || size < 1)
	{
		std::cout << "Введенный размер неверен";
		return 0;
	}
	else
		return 1;
}

void Input_array(int32_t* arr, int32_t size) {
	for (int i = 0; i < size; i++)
		std::cin >> arr[i];

}

void Buble_sort(int32_t* arr, int32_t size, int32_t count_elem, int32_t znak) {
	int32_t ind_key, key;
	for (int j = 0; j < size - 1; j++)
	{
		for (int32_t i = 0; i < size - j - 1; i++)
		{
			if (znak == -1 && arr[i] < 0)
			{
				ind_key = i;
				key = arr[i];
			}
			if (znak == -1 &&  key < arr[i + 1] && arr[i + 1] < 0)
			{
				std::swap(arr[i + 1], arr[ind_key]);
			}

			if (znak == 1 && arr[i] > 0)
			{
				ind_key = i;
				key = arr[i];
			}
			if (znak == 1 && key > arr[i + 1] && arr[i + 1] > 0)
			{
				std::swap(arr[i + 1], arr[ind_key]);
			}
		}
	}

}

int main() {
	const uint32_t MAX_SIZE = 1000;
	int32_t arr[MAX_SIZE];
	int32_t size, count_p = 0;
	int32_t count_z = 0;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размер массива" << '\n';
	std::cin >> size;
	if (Check_size(size, MAX_SIZE))
	{
		std::cout << "Введите массив" << '\n';
		Input_array(arr, size);
		Buble_sort(arr, size, count_p, -1);
		Output_array(arr, size);

	}

	return 0;
}
