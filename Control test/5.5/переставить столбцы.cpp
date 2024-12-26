#include <iostream>
#include <ctime>
#include <iomanip> //��� ������������� ������������ �����

void Output(int32_t**, int32_t, int32_t);

int main() {
	int32_t n, m, k;  //������ �-�� � 0 �������
	int32_t** a;
	srand(time(NULL));
	std::cin >> n >> m;
	a = new int32_t * [n];
	for (int i = 0; i < n; i++)
		a[i] = new int32_t[m];
	for (int32_t i = 0; i < n; i++)
		for (int32_t j = 0; j < m; j++)
			a[i][j] = rand() % (20) - 10;
	Output(a, n, m);
	std::cin >> k;
	for (int32_t i = 0; i < m; i++)
		std::swap(a[i][0], a[i][k - 1]);
	Output(a, n, m);
	for (int32_t i = 0; i < n; i++)
		delete[i] a;
	delete[] a;

}

void Output(int32_t** arr, int32_t n, int32_t m) {
	for (int32_t i = 0; i < n; i++)
	{
		for (int32_t j = 0; j < m; j++)
			std::cout << std::setw(2) << arr[i][j] << ' ';
		std::cout << '\n' << '\n';
	}
}

