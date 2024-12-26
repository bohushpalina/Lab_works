#include <iostream>
//треугольник Паскаля
int main() {
	int32_t str;
	int32_t j;
	int32_t** arr = nullptr;
	std::cout << "Enter cout of str" << '\n';
	std::cin >> str;
	arr = new int32_t * [str];
	for (int32_t i = 0; i < str; i++)
	{
		arr[i] = new int32_t[i + 2];
	}
	arr[0][0] = 1;
	arr[0][1] = 1;
	for (int32_t i = 1; i < str; i++)
	{
		arr[i][0] = 1;
		for (j = 1; j <= i; j++)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		arr[i][j] = 1;
	}
	for (int32_t i = 0; i < str; i++)
	{
		for (int32_t j = 0; j <= i + 1; j++)
			std::cout << arr[i][j] << " ";
		std::cout << "\n";
	}
	for (int32_t i = 0; i < str; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}