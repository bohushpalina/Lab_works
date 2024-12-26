#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
#include <cstring>

void CheckFile(std::ifstream&);
void CheckFile(std::ofstream&);
void Output(std::ofstream&, std::map<std::string, int32_t>&);
void CheckWord(std::string, std::map<std::string, int32_t>&);
void ReadFile(std::ifstream&, std::map<std::string, int32_t>&);
std::string ToLower(std::string word);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, int32_t> Counts;
	std::ifstream file("Input.txt");
	std::ofstream outfile("Output.txt");
	try
	{
		CheckFile(file);
		CheckFile(outfile);
		ReadFile(file, Counts);
		Output(outfile, Counts);
		std::cout << "Программа успешно завершила работу\n";
	}
	catch (const char* str) { std::cout << str; }
	file.close();
	outfile.close();
	return 0;
}

void CheckFile(std::ifstream& file) {
	if (!file)
		throw "Входной файл не существует\n";
	if (!file.is_open())
		throw "Входной файл не открылся\n";
	if (file.peek() == EOF)
		throw "Входной файл пуст\n";
}

void CheckFile(std::ofstream& file) { 
	if (!file)
		throw "Выходной файл не существует\n";
	if (!file.is_open())
		throw "Входной файл не открылся\n";
}

void Output(std::ofstream& outfile, std::map<std::string, int32_t>& Counts) {
	outfile << "Список всех слов:\n";
	for (auto it = Counts.begin(); it != Counts.end(); ++it)
	{
		outfile << it->first;
		outfile << '\n';
	}
	outfile << "Список всех слов с количество вхождения каждого:\n";
	for (auto it_1 = Counts.begin(); it_1 != Counts.end(); ++it_1)
	{
		outfile << "Слово: " << it_1->first << ", кол-во вхождений: " << it_1->second;
		outfile << '\n';
	}

}



void CheckWord(std::string word, std::map<std::string, int32_t>& Counts) { 
	word = ToLower(word);
	auto it = Counts.find(word);
	if (it == Counts.end())
	{
		Counts[word] = 1;
	}
	else
	{
		++Counts[word];
	}
}

void ReadFile(std::ifstream& file, std::map<std::string, int32_t>& Counts) {
	std::string string, delims = " ,./&!?", word;
	while (std::getline(file, string))
	{
		size_t BegInd, EndInd;
		BegInd = string.find_first_not_of(delims);
		while (BegInd != std::string::npos)
		{
			EndInd = string.find_first_of(delims, BegInd);
			if (EndInd == std::string::npos)
				EndInd = string.length();
			word = string.substr(BegInd, EndInd - BegInd);
			CheckWord(word, Counts);
			BegInd = string.find_first_not_of(delims, EndInd);
		}
	}

}

std::string ToLower(std::string word) {
	for (size_t i = 0; i < word.size(); ++i)
	{
		word[i] = std::tolower(word[i]);
	}
	return word;
}