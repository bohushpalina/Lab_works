#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <numeric>

void EnterSizesForMatrix(std::vector<std::vector<int32_t>>&, int32_t&, int32_t&, int32_t&, int32_t&);
void PrintMatrix(const std::vector<std::vector<int32_t>>&);
void SortRows(std::vector<std::vector<int32_t>>&);
void GenerateMatrix(std::vector<std::vector<int32_t>>&, int32_t&, int32_t&, int32_t&, int32_t&);
void DeleteRowAndColumnBiggestElement(std::vector<std::vector<int32_t>>&);




int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::vector<int32_t>> matrix;
	int32_t n, m, min, max;
	try
	{
		EnterSizesForMatrix(matrix, n, m, min, max);
		GenerateMatrix(matrix, n, m, min, max);
		DeleteRowAndColumnBiggestElement(matrix);
		SortRows(matrix);
		std::cout << "Отсортировали матрицу по возрастанию сумм элементов строк: " << '\n';
		PrintMatrix(matrix);
	}
	catch (const char* str) { std::cout << str; }
	return 0;
}

void EnterSizesForMatrix(std::vector<std::vector<int32_t>>& matrix, int32_t& n, int32_t& m, int32_t& min, int32_t& max)
{
	std::cout << "Введите размеры матрицы (строка, столбец): ";
	std::cin >> n >> m;
	if (n < 1 || m < 1)
		throw "Неверные размеры матрицы";
	std::cout << "Введите максимальное и минимальное значение для генерации значений матрицы: ";
	std::cin >> min >> max;
	if (min > max)
	{
		std::swap(min, max);
	}
}

void PrintMatrix(const std::vector<std::vector<int32_t>>& matrix)
{
	for (int32_t i = 0; i < matrix.size(); ++i)
	{
		for (int32_t j = 0; j < matrix[i].size(); ++j)
		{
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << '\n';
	}
}

void SortRows(std::vector<std::vector<int32_t>>& matrix) {
	for (size_t i = 0; i < matrix.size() - 1; ++i) {
		for (size_t j = 0; j < matrix.size() - i - 1; ++j) {
			int32_t sum1 = 0, sum2 = 0;
			for (int32_t k = 0; k < matrix[j].size(); ++k)
				sum1 = sum2 = std::accumulate(matrix[j].begin(), matrix[j].end(), 0);
			for (int32_t k = 0; k < matrix[j + 1].size(); ++k)
				sum2 = std::accumulate(matrix[j + 1].begin(), matrix[j + 1].end(), 0);

			if (sum1 > sum2) {
				std::swap(matrix[j], matrix[j + 1]);
			}
		}
	}
}

void GenerateMatrix(std::vector<std::vector<int32_t>>& matrix, int32_t& n, int32_t& m, int32_t& min, int32_t& max)
{
	srand(time(NULL));
	std::vector<int32_t> str;
	for (int32_t i = 0; i < n; ++i)
	{
		str.clear();
		for (int32_t j = 0; j < m; ++j)
		{
			str.push_back(rand() % (max - min + 1) + min);
		}
		matrix.push_back(str);
	}
	std::cout << "Сгенерированная матрица: " << '\n';
	PrintMatrix(matrix);
}

void DeleteRowAndColumnBiggestElement(std::vector<std::vector<int32_t>>& matrix)
{
	int32_t max_col = -1, max_row = -1;
	int32_t Max = INT_MIN;
	std::vector<int32_t> str;
	for (size_t i = 0; i < matrix.size(); ++i) {  //column - столбец          row -  строка
		auto max_el_it = std::max_element(matrix[i].begin(), matrix[i].end());
		int32_t max_el = *max_el_it;
		if (max_el > Max) {
			Max = max_el;
			max_row = i;
			str = matrix[i];
			max_col = std::distance(matrix[i].begin(), max_el_it);
		}
	}

	matrix.erase(matrix.begin() + max_row);
	// Удаляем столбец с максимальным элементом
	for (int32_t i = 0; i < matrix.size(); ++i) {
		matrix[i].erase(matrix[i].begin() + max_col);
	}
	std::cout << "Удалили строку и столбец наибольшего элемента: " << '\n';
	PrintMatrix(matrix);
}