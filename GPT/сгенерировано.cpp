#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <windows.h>

bool is_palindrome(const std::string& word) {
    std::string cleaned_word;

    // ������� ������� � �������� � ������� ��������
    for (char ch : word) {
        if (std::isalnum(ch)) { // ���������, �������� �� ������ ������ ��� ������
            cleaned_word += std::tolower(ch);
        }
    }

    // ���������, �������� �� ����� �����������
    std::string reversed_word = std::string(cleaned_word.rbegin(), cleaned_word.rend());
    return cleaned_word == reversed_word;
}

std::vector<std::string> find_longest_palindromes(const std::string& input_string) {
    std::vector<std::string> palindromes;
    std::istringstream stream(input_string);
    std::string word;

    // ��������� ������ �� �����
    while (stream >> word) {
        // ������� ����� ���������� � ������ ����
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (is_palindrome(word) && !word.empty()) {
            palindromes.push_back(word);
        }
    }

    return palindromes;
}

int main() {
    std::string input_string;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "������� ������: ";
    std::getline(std::cin, input_string);

    std::vector<std::string> palindromes = find_longest_palindromes(input_string);

    if (palindromes.empty()) {
        std::cout << "���������� �� �������." << std::endl;
        return 0;
    }

    // ���������� ������������ ����� �����������
    size_t max_length = 0;
    for (const auto& palindrome : palindromes) {
        max_length = std::max(max_length, palindrome.length());
    }

    // ���� ����� ������� �����������
    std::vector<std::string> longest_palindromes;
    for (const auto& palindrome : palindromes) {
        if (palindrome.length() == max_length) {
            longest_palindromes.push_back(palindrome);
        }
    }

    // ����� ����������
    std::cout << "����� ������� ����������: ";
    for (size_t i = 0; i < longest_palindromes.size(); ++i) {
        std::cout << longest_palindromes[i];
        if (i < longest_palindromes.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}

