#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <set>
#include <stdexcept>

void PrintVector(const std::vector<int32_t>&);
void EnterNumbers(std::vector<int32_t>&, int32_t&);
void CalculateAndPrintSum(const std::vector<int32_t>& numbers, int32_t& sum);
void CountAndPrintNumbers(const std::vector<int32_t>& numbers);
void CountAndPrintNumberInVector(const std::vector<int32_t>& numbers);
void CountAndPrintConditional(const std::vector<int32_t>& numbers);
void ReplaceZerosWithAverage(std::vector<int32_t>& numbers, int32_t& sum);
void AddIntervalSum(std::vector<int32_t>& numbers);
void ReplaceEvensWithDifference(std::vector<int32_t>& numbers);
void RemoveEqualByMagnitude(std::vector<int32_t>& numbers);

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int32_t> numbers;
    int32_t input, sum;
    try
    {
        EnterNumbers(numbers, input);
        CalculateAndPrintSum(numbers, sum);
        CountAndPrintNumbers(numbers);
        CountAndPrintNumberInVector(numbers);
        CountAndPrintConditional(numbers);
        ReplaceZerosWithAverage(numbers, sum);
        AddIntervalSum(numbers);
        ReplaceEvensWithDifference(numbers);
        RemoveEqualByMagnitude(numbers);
    }
    catch (const std::invalid_argument& e) { std::cerr << e.what() << '\n'; }
    return 0;
}

void PrintVector(const std::vector<int32_t>& numbers)
{
    for (int32_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << '\n';
}

void EnterNumbers(std::vector<int32_t>& numbers, int32_t& input)
{
    std::cout << "Введите числа (для завершения ввода введите любой символ, кроме цифры):" << '\n';
    while (std::cin >> input)
    {
        numbers.push_back(input);
    }
    if (std::cin.fail() && !std::cin.eof())
    {
        std::cout << "Ввод завершен" << '\n';
    }
    std::cin.clear();      // Очистка состояния cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //смещение указателя потока в самый конец
}

void CalculateAndPrintSum(const std::vector<int32_t>& numbers, int32_t& sum)
{
    sum = std::accumulate(numbers.begin(), numbers.end(), 0);  // Подсчет суммы чисел
    std::cout << "Сумма чисел: " << sum << '\n';
}

void CountAndPrintNumbers(const std::vector<int32_t>& numbers)
{
    std::cout << "Количество введенный чисел: " << numbers.size() << '\n';
}

void CountAndPrintNumberInVector(const std::vector<int32_t>& numbers)
{
    int32_t target;
    std::cout << "Введите число для подсчета его вхождений: ";
    std::cin >> target;
    int32_t count_num = std::count(numbers.begin(), numbers.end(), target);   // Количество чисел, равных заданному
}

void CountAndPrintConditional(const std::vector<int32_t>& numbers)
{
    int32_t n;
    std::string conditional;
    std::cout << "Введите число n для подсчета с выражением: ";
    std::cin >> n;
    std::cout << "Введите условие для поиска чисел, относительно n: \n";
    std::cout << "Возможный ввод условия: > < = != <= >= \n";
    std::cout << "Пример: при вводе 2 и >= будут искаться все числа, равные или больше 2 \n";
    std::cin >> conditional;
        int32_t count_n = std::count_if(numbers.begin(), numbers.end(), [n, conditional](int32_t num) {
            if (conditional == ">")
                return num > n;
            else if (conditional == ">=")
                return num >= n;
            else if (conditional == "=")
                return num == n;
            else if (conditional == "<")
                return num < n;
            else if (conditional == "<=")
                return num <= n;
            else if (conditional == "!=")
                return num != n;
            else
                throw std::invalid_argument("Неверное условие!");
            });
    std::cout << "Количество чисел, удовлетворяющих заданному условию: " << count_n << '\n';
}

void ReplaceZerosWithAverage(std::vector<int32_t>& numbers, int32_t& sum)
{
    if (!numbers.empty())
    {
        int32_t average = sum / numbers.size();
        std::replace(numbers.begin(), numbers.end(), 0, average);   // Замена всех нулей средним арифметическим
        std::cout << "Замена всех нулей средним арифметическим: ";
        PrintVector(numbers);
    }
    else
        throw std::invalid_argument("Вектор пуст, работа с пустым вектором нецелесообразна");
}

void AddIntervalSum(std::vector<int32_t>& numbers)
{
    int32_t start, end;
    std::cout << "Введите начало и конец интервала (индексы, отсчет с нуля): ";
    std::cin >> start >> end;    // Добавление к каждому элементу суммы всех чисел из заданного интервала
    if (start > end)
    {
        std::swap(start, end);
    }
    if (start >= 0 && end < numbers.size()) {
        int32_t interval_sum = std::accumulate(numbers.begin() + start, numbers.begin() + end + 1, 0);
        std::cout << "Сумма чисел заданного интервала: " << interval_sum << '\n';
        for (int32_t i = 0; i < numbers.size(); ++i) {
            numbers[i] = numbers[i] + interval_sum;
        }
        std::cout << "Добавим к каждому числу сумму всех чисел из заданного интервала: ";
        PrintVector(numbers);
    }
    else
    {
        std::cout << "Неверный интервал" << '\n';
    }
}

void ReplaceEvensWithDifference(std::vector<int32_t>& numbers)
{
    int32_t minElem = *std::min_element(numbers.begin(), numbers.end());
    int32_t maxElem = *std::max_element(numbers.begin(), numbers.end());
    int32_t difference = maxElem - minElem;
    std::cout << "разность минимального и максимального числа вектора: " << difference << '\n';
    for (int32_t i = 0; i < numbers.size(); ++i) {   // Замена чисел с четным модулем на разность минимального и максимального чисел
        if (std::abs(numbers[i]) % 2 == 0) {
            numbers[i] = difference;
        }
    }
    std::cout << "Замена чисел с четным модулем на разность минимального и максимального чисел: ";
    PrintVector(numbers);
}

void RemoveEqualByMagnitude(std::vector<int32_t>& numbers)
{
    auto endIt = std::unique(numbers.begin(), numbers.end(), [](int a, int b) { return std::abs(a) == std::abs(b); });
    numbers.erase(endIt, numbers.end());
    std::cout << "Удаление всех равных по модулю чисел, кроме первого из них:" << '\n';
    PrintVector(numbers);
}