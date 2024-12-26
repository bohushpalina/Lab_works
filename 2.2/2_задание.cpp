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
    std::cout << "������� ����� (��� ���������� ����� ������� ����� ������, ����� �����):" << '\n';
    while (std::cin >> input)
    {
        numbers.push_back(input);
    }
    if (std::cin.fail() && !std::cin.eof())
    {
        std::cout << "���� ��������" << '\n';
    }
    std::cin.clear();      // ������� ��������� cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //�������� ��������� ������ � ����� �����
}

void CalculateAndPrintSum(const std::vector<int32_t>& numbers, int32_t& sum)
{
    sum = std::accumulate(numbers.begin(), numbers.end(), 0);  // ������� ����� �����
    std::cout << "����� �����: " << sum << '\n';
}

void CountAndPrintNumbers(const std::vector<int32_t>& numbers)
{
    std::cout << "���������� ��������� �����: " << numbers.size() << '\n';
}

void CountAndPrintNumberInVector(const std::vector<int32_t>& numbers)
{
    int32_t target;
    std::cout << "������� ����� ��� �������� ��� ���������: ";
    std::cin >> target;
    int32_t count_num = std::count(numbers.begin(), numbers.end(), target);   // ���������� �����, ������ ���������
}

void CountAndPrintConditional(const std::vector<int32_t>& numbers)
{
    int32_t n;
    std::string conditional;
    std::cout << "������� ����� n ��� �������� � ����������: ";
    std::cin >> n;
    std::cout << "������� ������� ��� ������ �����, ������������ n: \n";
    std::cout << "��������� ���� �������: > < = != <= >= \n";
    std::cout << "������: ��� ����� 2 � >= ����� �������� ��� �����, ������ ��� ������ 2 \n";
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
                throw std::invalid_argument("�������� �������!");
            });
    std::cout << "���������� �����, ��������������� ��������� �������: " << count_n << '\n';
}

void ReplaceZerosWithAverage(std::vector<int32_t>& numbers, int32_t& sum)
{
    if (!numbers.empty())
    {
        int32_t average = sum / numbers.size();
        std::replace(numbers.begin(), numbers.end(), 0, average);   // ������ ���� ����� ������� ��������������
        std::cout << "������ ���� ����� ������� ��������������: ";
        PrintVector(numbers);
    }
    else
        throw std::invalid_argument("������ ����, ������ � ������ �������� ���������������");
}

void AddIntervalSum(std::vector<int32_t>& numbers)
{
    int32_t start, end;
    std::cout << "������� ������ � ����� ��������� (�������, ������ � ����): ";
    std::cin >> start >> end;    // ���������� � ������� �������� ����� ���� ����� �� ��������� ���������
    if (start > end)
    {
        std::swap(start, end);
    }
    if (start >= 0 && end < numbers.size()) {
        int32_t interval_sum = std::accumulate(numbers.begin() + start, numbers.begin() + end + 1, 0);
        std::cout << "����� ����� ��������� ���������: " << interval_sum << '\n';
        for (int32_t i = 0; i < numbers.size(); ++i) {
            numbers[i] = numbers[i] + interval_sum;
        }
        std::cout << "������� � ������� ����� ����� ���� ����� �� ��������� ���������: ";
        PrintVector(numbers);
    }
    else
    {
        std::cout << "�������� ��������" << '\n';
    }
}

void ReplaceEvensWithDifference(std::vector<int32_t>& numbers)
{
    int32_t minElem = *std::min_element(numbers.begin(), numbers.end());
    int32_t maxElem = *std::max_element(numbers.begin(), numbers.end());
    int32_t difference = maxElem - minElem;
    std::cout << "�������� ������������ � ������������� ����� �������: " << difference << '\n';
    for (int32_t i = 0; i < numbers.size(); ++i) {   // ������ ����� � ������ ������� �� �������� ������������ � ������������� �����
        if (std::abs(numbers[i]) % 2 == 0) {
            numbers[i] = difference;
        }
    }
    std::cout << "������ ����� � ������ ������� �� �������� ������������ � ������������� �����: ";
    PrintVector(numbers);
}

void RemoveEqualByMagnitude(std::vector<int32_t>& numbers)
{
    auto endIt = std::unique(numbers.begin(), numbers.end(), [](int a, int b) { return std::abs(a) == std::abs(b); });
    numbers.erase(endIt, numbers.end());
    std::cout << "�������� ���� ������ �� ������ �����, ����� ������� �� ���:" << '\n';
    PrintVector(numbers);
}