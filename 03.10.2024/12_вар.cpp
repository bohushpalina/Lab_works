//В массиве, состоящем из п целых элементов, вычислить: 
// - количество положительных элементов массива; 
// - сумму элементов массива, расположенных после последнего элемента, равного нулю.
//Все положительные элементы массива расположить по возрастанию, все отрицательные - по убыванию, нули оставить на месте.

#include <iostream>

void CountAfterZero(int32_t*, int32_t, int32_t&);
void CheckZero(int32_t*, int32_t);
void CountPosElem(int32_t*, int32_t, int32_t&);
void InputArray(int32_t*, int32_t);
void CheckSize(int32_t, int32_t);
void BubleSort(int32_t*, int32_t, int32_t);
void OutputArray(int32_t*, int32_t);
void RandomArray(int32_t*, int32_t);



int main() {
	try {
		const uint32_t MAX_SIZE = 1000;
		int32_t arr[MAX_SIZE];
		int32_t size, count_p = 0, count_z = 0, var;
		setlocale(LC_ALL, "Russian");
		std::cout << "Введите размер массива (меньше или равное 1000)" << '\n';
		std::cin >> size;
		CheckSize(size, MAX_SIZE); //проверка на размер массива 
		std::cout << "Желаете ввести с клавиатуры (введите 1) или сгенерировать массив (введите 2)?" << '\n';
		std::cin >> var;
		switch (var) {

		case 1: std::cout << "Введите массив" << '\n';
			InputArray(arr, size);
			break;
		case 2: std::cout << "Массив будет сгенерирован автоматически" << '\n';
			RandomArray(arr, size);
			std::cout << "Ваш массив: " << '\n';
			OutputArray(arr, size);
			std::cout << '\n';
			break;
		default: throw "Неверный ввод"; 
		}
		CountPosElem(arr, size, count_p);
		std::cout << "Количество положительных элементов: " << count_p << "\n";
		try
		{
			CheckZero(arr, size);
			CountAfterZero(arr, size, count_z);
			std::cout << "Сумма элементов массива, расположенных после последнего элемента массива, равного 0: " << count_z << '\n';
		}
		catch (const char* str) {
			std::cout << str << '\n';
		}
		BubleSort(arr, size, 1); //пузырьковая сортировка для положительных элементов
		BubleSort(arr, size, -1); //пузырьковая сортировка для отрицательных элементов
		std::cout << "Вывод отсортированного массива: ";
		OutputArray(arr, size);
	} catch (const char* str) {
			std::cout << str;
	}
	return 0;
}


void OutputArray(int32_t* arr, int32_t size) { //цикл вывода массива
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

}

void BubleSort(int32_t* arr, int32_t size, int32_t znak) { //пузырьковая сортировка для положительных/отрицательных чисел
	int32_t ind_key = 0, key = arr[0];
	for (int j = 0; j < size - 1; j++)
	{
		for (int32_t i = 0; i < size - j - 1; i++)
		{
			if (znak == -1 && arr[i] < 0) //сортировка отрицательных чисел
			{
				ind_key = i;
				key = arr[i];
			}
			if (znak == -1 && key < arr[i + 1] && arr[i + 1] < 0 && key < 0) //по убыванию
				std::swap(arr[i + 1], arr[ind_key]);

			if (znak == 1 && arr[i] > 0) //сортировка положительных
			{
				ind_key = i;
				key = arr[i];
			}
			if (znak == 1 && key > arr[i + 1] && arr[i + 1] > 0 && key > 0) //по возрастанию
				std::swap(arr[i + 1], arr[ind_key]);
		}
	}

}


void CheckSize(int32_t size, int32_t max) { //Проверка, является ли размер массива меньше константы
	if (size > max || size < 1)
		throw "Введенный размер неверен"; 
}

void InputArray(int32_t* arr, int32_t size) { //цикл ввода массива
	for (int i = 0; i < size; i++)
		std::cin >> arr[i];

}

void CountPosElem(int32_t* arr, int32_t size, int32_t& count_p) { //подсчитывает кол-во положительных чисел в массиве
	for (int i = 0; i < size; i++)
		if (arr[i] > 0)
			count_p += 1;
}

void CheckZero(int32_t* arr, int32_t size) { //проверка на кол-во и последнее вхождение нуля в массив
	int32_t count_zero = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == 0)
			count_zero += 1;
	if (count_zero == 0)
	{
		throw "Нет нулей в массиве";
	}
	else if (arr[size - 1] == 0)
	{
		throw "Ноль стоит последним элементом";
	}
}

void CountAfterZero(int32_t* arr, int32_t size, int32_t& count_z) { //считает сумму элементов после нуля
	uint32_t i = 0;
	while (arr[size - 1 - i] != 0)
	{
		count_z += arr[size - 1 - i];
		i++;
	}
}


void RandomArray(int32_t* arr, int32_t size) { //генерация массива с вводом верхней и нижней границы
	int32_t max, min;
	srand(time(0));
	std::cout << "Введите минимальное и максимальное числа для генерации массива" << '\n';
	std::cin >> min >> max;
	if (min > max)
		std::swap(min, max);
	for (int i = 0; i < size; i++)
		arr[i] = rand()  % (max - min + 1) + min; //формула для ограничения рандома: (А, B) -> rand() % (B - A + 1) + A
}