#include <iostream>

int main() {
	int32_t n, m;
	int32_t** a;
	std::cin >> n >> m;
	a = new int32_t * [n];
	for (int i = 0; i < n; i++)
		a[i] = new int32_t[m];
	for (int32_t i = 0; i < n; i++)
		for (int32_t j = 0; j < m; j++)
			a[i][j] = std::max(i, j);
	for (int32_t i = 0; i < n; i++)
	{
		for (int32_t j = 0; j < m; j++)
			std::cout << a[i][j]  << " ";
		std::cout << '\n' << '\n';
	}
	for (int32_t i = 0; i < n; i++)
		delete[i] a;
	delete[] a;
	
}