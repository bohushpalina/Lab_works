//��� �������� ������������ ����� n
#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, ".1251");
	long int number, min, max;
	cout << "������� �����" << endl;
	cin >> number;
	cout << "1" << '\n'; // �������� 1
	for (min = 2, max = number / 2; min <= max; min++) { // d � ��������������
		// ��������
		if (number % min == 0) { // n ����������� �� d
			cout << min << '\n';
		}
	}
	cout << number << '\n'; // �������� - ���� �����
	return 0;
}
