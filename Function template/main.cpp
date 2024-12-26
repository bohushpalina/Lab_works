#include <iostream>
#include <fstream>
#include <windows.h>

void FileInputAndOutput();
void GenerateAndFileOutput();
void FromFileToConsole();
void CheckFiles(std::ifstream&, std::ofstream&);

template <typename T>
void myFunction(T arg) {
    // Код функции
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try
    {
        int32_t y;
        std::cout << "Выберите метод ввода: 1 - непосредственный ввод и запись в текстовый файл; 2 - генерирование с помощью датчика случайных чисел и запись в текстовый файл; 3 - ввод из текстового файла, а вывод - в консоль. ";
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
            throw "Неверный ввод";
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
