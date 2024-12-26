#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

//В задаче не сказано, что слова с символами разного регистра считаются одинаковыми.

void CheckFiles(std::ifstream&, std::ofstream&);
void ReadFile(std::ifstream&, std::vector <std::string>&);
void OutputFile(std::ofstream&, std::vector <std::string>&);
void RemakeString(std::string&, std::vector<int32_t>&, std::string, std::string);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream ifile("IN51.txt");
	std::ofstream outfile("OUT51.txt");
	std::vector <std::string> vector;
	try {
		CheckFiles(ifile, outfile);
		ReadFile(ifile, vector);
		OutputFile(outfile, vector);
	}
	catch (const char* str) { std::cout << str; }
	ifile.close();
	outfile.close();
	std::cout << "Файлы закрыты\n";
	return 0;
}


void CheckFiles(std::ifstream& ifile, std::ofstream& outfile) {  //проверки для файлов
	if (!ifile || !outfile)
		throw "Файлы не существуют\n";
	if (!ifile.is_open() || !outfile.is_open())
		throw "Файлы не открылись";
	std::cout << "Файлы открыты\n";
	if (ifile.peek() == EOF)
		throw "Входной файл пуст\n";

}

void ReadFile(std::ifstream& ifile, std::vector <std::string>& vector)
{
	std::string inword, sentence, delims; //проверка наличия минимум 4 строк в файле
	std::getline(ifile, inword);
	if (ifile.peek() == EOF)
		throw "Недостаточно вводных данных\n";
	std::getline(ifile, sentence);
	if (ifile.peek() == EOF)
		throw "Недостаточно вводных данных\n";
	std::getline(ifile, delims);
	if (ifile.peek() == EOF)
		throw "Отстутсвует текст для обработки\n";
	std::cout << "Начато чтение файла\n";

	size_t BegIn, EndIn;
	std::vector <int32_t> arr;
	std::string string, word;
	while (std::getline(ifile, string))  //чтение файла построчно
	{
		arr.clear();
		BegIn = string.find_first_not_of(delims);
		while (BegIn != std::string::npos) //алгоритм выделения слов
		{
			EndIn = string.find_first_of(delims, BegIn);
			if (EndIn == std::string::npos)
				EndIn = string.size();
			word = string.substr(BegIn, EndIn - BegIn); //полученное слово
			if (word == inword)
				arr.push_back(BegIn); //добавление начальной позиции слова в вектор
			BegIn = string.find_first_not_of(delims, EndIn);
		}
		RemakeString(string, arr, inword, sentence);
		vector.push_back(string); //запись в вектор измененных строк
	}
}

void OutputFile(std::ofstream& outfile, std::vector <std::string>& vector)  //вывод построчно из вектора строк в выходной файл
{
	std::cout << "Начата запись выходного файла\n";
	for (int32_t i = 0; i < vector.size(); i++)
	{
		outfile << vector[i];
		outfile << '\n';
	}
	std::cout << "Запись выходного файла закончена\n";
}

void RemakeString(std::string& string, std::vector<int32_t>& arr, std::string inword, std::string sentence)  //замена слов на предложение с конца строки 
{                                                                                             //для предотвращанеия появления сдвигов в начальных позициях слов
	for (int i = 0; i < arr.size(); i++)
	{
		string.replace(arr[arr.size() - i - 1], inword.size(), sentence);
	}
}