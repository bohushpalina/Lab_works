#include <iostream>
#include <cmath>
//���������� ������� ��������� 
bool Check(int32_t);

int main()
{
	uint32_t n;
	bool ex = 1;
	setlocale(LC_ALL, "Russian");
	std::cin >> n;
	if (n == 2 || n == 3)
	{
		std::cout << "����� �������";
	}
	else //����� ������� ��� ��� 
		//(������ ��� ������ �������� ����� 1)
	{
		for (int32_t i = 2; i < int32_t(abs(int(n))); i++)
			if (n % i == 0)
			{
				if (Check(i))
				{
					std::cout << i << " ";
					ex = 0;
				}
			}
		if (ex)
			std::cout << "����� �������";
	}
	return 0;
}

bool Check(int32_t numb) {
	for (int i = 2; i < int(abs(int(numb))); i++)
		if (numb % i == 0)
			return 0;
	return 1;
}

