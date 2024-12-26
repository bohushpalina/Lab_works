#include <iostream>

int32_t Sum_Deg(int32_t num) {
	int32_t sum = 0;
	for (int32_t i = 1; i < num; i++)
	{
		if (num % i == 0)
			sum += i;
	}
	return sum;
}


int main() { //нахождение дружественных чисел
	uint32_t a, b;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите целые положительные числа - ограничения промежутков: ";
	std::cin >> a >> b;
	if (a > b) std::swap(a, b);
	int32_t i1, j1;
	for (int i = a; i <= b; ++i) {
		i1 = Sum_Deg(i);
		for (int j = i + 1; j <= b; ++j)
		{
				j1 = Sum_Deg(j);
				if (j1 == i && i1 == j)
					std::cout << "Пара дружественых чисел: " << i << ', ' << j << '\n';
		}
	}
	

	return 0;
}