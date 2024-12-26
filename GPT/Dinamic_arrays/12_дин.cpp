//� �������, ��������� �� � ����� ���������, ���������: 
// - ���������� ������������� ��������� �������; 
// - ����� ��������� �������, ������������� ����� ���������� ��������, ������� ����.
//��� ������������� �������� ������� ����������� �� �����������, ��� ������������� - �� ��������, ���� �������� �� �����.
#include <iostream>

void CountAfterZero(int32_t*, int32_t, int32_t&);
void CheckZero(int32_t*, int32_t);
void CountPosElem(int32_t*, int32_t, int32_t&);
void InputArray(int32_t*, int32_t);
void CheckSize(int32_t);
void BubleSort(int32_t*, int32_t, int32_t);
void OutputArray(int32_t*, int32_t);
void RandomArray(int32_t*, int32_t);
void DeleteArray(int32_t*&, int32_t);
void LocateArray(int32_t*&, int32_t);
void InputSize(int32_t&);



int main() {
	int32_t* arr = nullptr;
	int32_t size;
	try {
		int32_t count_p = 0, count_z = 0, var;
		setlocale(LC_ALL, "Russian");
		InputSize(size);
		CheckSize(size); //�������� �� ������ ������� 
		LocateArray(arr, size);
		std::cout << "������� ������ � ���������� (������� 1) ��� ������������� ������ (������� 2)?" << '\n';
		std::cin >> var;
		switch (var) {

		case 1: std::cout << "������� ������" << '\n';
			InputArray(arr, size);
			break;
		case 2: std::cout << "������ ����� ������������ �������������" << '\n';
			RandomArray(arr, size);
			std::cout << "��� ������: " << '\n';
			OutputArray(arr, size);
			std::cout << '\n';
			break;
		default: throw "�������� ����";
		}
		CountPosElem(arr, size, count_p);
		std::cout << "���������� ������������� ���������: " << count_p << "\n";
		try
		{
			CheckZero(arr, size);
			CountAfterZero(arr, size, count_z);
			std::cout << "����� ��������� �������, ������������� ����� ���������� �������� �������, ������� 0: " << count_z << '\n';
		}
		catch (const char* str) {
			std::cout << str << '\n';
		}
		BubleSort(arr, size, 1); //����������� ���������� ��� ������������� ���������
		BubleSort(arr, size, -1); //����������� ���������� ��� ������������� ���������
		std::cout << "����� ���������������� �������: ";
		OutputArray(arr, size);
	}
	catch (const char* str) {
		std::cout << str;
	}
	DeleteArray(arr, size);
	return 0;
}


void OutputArray(int32_t* arr, int32_t size) { //���� ������ �������
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

}

void BubleSort(int32_t* arr, int32_t size, int32_t znak) { //����������� ���������� ��� �������������/������������� �����
	int32_t ind_key = 0, key = arr[0];
	for (int j = 0; j < size - 1; j++)
	{
		for (int32_t i = 0; i < size - j - 1; i++)
		{
			if (znak == -1 && arr[i] < 0) //���������� ������������� �����
			{
				ind_key = i;
				key = arr[i];
			}
			if (znak == -1 && key < arr[i + 1] && arr[i + 1] < 0 && key < 0) //�� ��������
				std::swap(arr[i + 1], arr[ind_key]);

			if (znak == 1 && arr[i] > 0) //���������� �������������
			{
				ind_key = i;
				key = arr[i];
			}
			if (znak == 1 && key > arr[i + 1] && arr[i + 1] > 0 && key > 0) //�� �����������
				std::swap(arr[i + 1], arr[ind_key]);
		}
	}
}


void CheckSize(int32_t size) { //��������, �������� �� ������ ������� ������ ���������
	if (size < 1)
		throw "��������� ������ �������";
}

void InputArray(int32_t* arr, int32_t size) { //���� ����� �������
	for (int i = 0; i < size; i++)
		std::cin >> arr[i];

}

void CountPosElem(int32_t* arr, int32_t size, int32_t& count_p) { //������������ ���-�� ������������� ����� � �������
	for (int i = 0; i < size; i++)
		if (arr[i] > 0)
			count_p += 1;
}//!!!!!!!!!!!!!!!!!!

void CheckZero(int32_t* arr, int32_t size) { //�������� �� ���-�� � ��������� ��������� ���� � ������
	int32_t count_zero = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == 0)
			count_zero += 1;
	if (count_zero == 0)
	{
		throw "��� ����� � �������";
	}
	else if (arr[size - 1] == 0)
	{
		throw "���� ����� ��������� ���������";
	}
}

void CountAfterZero(int32_t* arr, int32_t size, int32_t& count_z) { //������� ����� ��������� ����� ����
	uint32_t i = 0;
	while (arr[size - 1 - i] != 0)
	{
		count_z += arr[size - 1 - i];
		i++;
	}
}


void RandomArray(int32_t* arr, int32_t size) { //��������� ������� � ������ ������� � ������ �������
	int32_t max, min;
	srand(time(0));
	std::cout << "������� ����������� � ������������ ����� ��� ��������� �������" << '\n';
	std::cin >> min >> max;
	if (min > max)
		std::swap(min, max);
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min + 1) + min; //������� ��� ����������� �������: (�, B) -> rand() % (B - A + 1) + A
}

void DeleteArray(int32_t*& arr, int32_t size) {
	delete[] arr;
}

void LocateArray(int32_t*& arr, int32_t size) {
	arr = new int32_t[size];
}

void InputSize(int32_t& size) {
	std::cout << "������� ������ �������" << '\n';
	std::cin >> size;
}