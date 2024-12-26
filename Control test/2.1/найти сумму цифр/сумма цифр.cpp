#include <iostream>

int main() {
	uint32_t n, sum = 0;
	std::cin >> n;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	std::cout << sum;
	return 0;
}