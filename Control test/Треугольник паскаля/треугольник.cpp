#include <iostream>

int main() {
	int32_t str;
	int32_t** arr = nullptr;
	std::cout << "Enter cout of str" << '\n';
	std::cin >> str;
	arr = new int32_t * [str];
	arr[0] = { 1, 1 };
	for (int32_t i = 1; i < str; i++)
	{
		arr[i][j] = 1;
		for (int32_t j = 1; j <= i + 1; j++)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j - 1];
		arr[i][j] = 1;
	}
	for (int32_t i = 0; i < str; i++)
		for (int32_t j = 0; j <= i + 1; j++)
			std::cout << a[i][j];
	for (int32_t i = 0; i < str; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}