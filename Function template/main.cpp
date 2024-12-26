#include <iostream>
#include <fstream>
#include <windows.h>

void FileInputAndOutput();
void GenerateAndFileOutput();
void FromFileToConsole();
void CheckFiles(std::ifstream&, std::ofstream&);

template <typename T>
void myFunction(T arg) {
    // ��� �������
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try
    {
        int32_t y;
        std::cout << "�������� ����� �����: 1 - ���������������� ���� � ������ � ��������� ����; 2 - ������������� � ������� ������� ��������� ����� � ������ � ��������� ����; 3 - ���� �� ���������� �����, � ����� - � �������. ";
        std::cin >> y;
        switch (y)
        {
        case 1:
            FileInputAndOutput();
        case 2:
            GenerateAndFileOutput();
        case 3:
            FromFileToConsole();
        default:
            throw "�������� ����";
        }
    }
    catch (const char* str) { std::cout << str; }



    return 0;
}

void FileInputAndOutput()
{
    std::ifstream ifile ("Input.txt");
    std::ofstream outfile("Output.txt");
    CheckFiles(ifile, outfile);
}
