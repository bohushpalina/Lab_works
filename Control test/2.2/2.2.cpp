//Все делители натурального числа n
#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, ".1251");
	long int number, min, max;
	cout << "введите число" << endl;
	cin >> number;
	cout << "1" << '\n'; // делитель 1
	for (min = 2, max = number / 2; min <= max; min++) { // d – предполагаемый
		// делитель
		if (number % min == 0) { // n разделилось на d
			cout << min << '\n';
		}
	}
	cout << number << '\n'; // делитель - само число
	return 0;
}
