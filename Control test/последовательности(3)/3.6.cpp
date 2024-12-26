#include <iostream>

int main() {
	int32_t* arr;
	uint32_t count = 0, sum = 0, max, min, amount;
	setlocale(LC_ALL, "Russian");
	std::cout << "¬ведите размер последовательности: ";
	std::cin >> amount;
	arr = new int32_t[amount];
	std::cout << "¬ведите последовательность: ";
	for (int32_t i = 0; i < amount; i++)
		std::cin >> arr[i];
	min = arr[0]; 
	max = arr[0];
	for (int32_t i = 0; i < amount; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	for (int32_t i = 0; i < amount; i++) {
		if (arr[i] != max && arr[i] != min)
		{
			sum += arr[i];
			count++;
		}
	}
	std::cout << double(sum) / count;
	return 0;
}