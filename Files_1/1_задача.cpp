#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

//� ������ �� �������, ��� ����� � ��������� ������� �������� ��������� �����������.

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
	std::cout << "����� �������\n";
	return 0;
}


void CheckFiles(std::ifstream& ifile, std::ofstream& outfile) {  //�������� ��� ������
	if (!ifile || !outfile)
		throw "����� �� ����������\n";
	if (!ifile.is_open() || !outfile.is_open())
		throw "����� �� ���������";
	std::cout << "����� �������\n";
	if (ifile.peek() == EOF)
		throw "������� ���� ����\n";

}

void ReadFile(std::ifstream& ifile, std::vector <std::string>& vector)
{
	std::string inword, sentence, delims; //�������� ������� ������� 4 ����� � �����
	std::getline(ifile, inword);
	if (ifile.peek() == EOF)
		throw "������������ ������� ������\n";
	std::getline(ifile, sentence);
	if (ifile.peek() == EOF)
		throw "������������ ������� ������\n";
	std::getline(ifile, delims);
	if (ifile.peek() == EOF)
		throw "����������� ����� ��� ���������\n";
	std::cout << "������ ������ �����\n";

	size_t BegIn, EndIn;
	std::vector <int32_t> arr;
	std::string string, word;
	while (std::getline(ifile, string))  //������ ����� ���������
	{
		arr.clear();
		BegIn = string.find_first_not_of(delims);
		while (BegIn != std::string::npos) //�������� ��������� ����
		{
			EndIn = string.find_first_of(delims, BegIn);
			if (EndIn == std::string::npos)
				EndIn = string.size();
			word = string.substr(BegIn, EndIn - BegIn); //���������� �����
			if (word == inword)
				arr.push_back(BegIn); //���������� ��������� ������� ����� � ������
			BegIn = string.find_first_not_of(delims, EndIn);
		}
		RemakeString(string, arr, inword, sentence);
		vector.push_back(string); //������ � ������ ���������� �����
	}
}

void OutputFile(std::ofstream& outfile, std::vector <std::string>& vector)  //����� ��������� �� ������� ����� � �������� ����
{
	std::cout << "������ ������ ��������� �����\n";
	for (int32_t i = 0; i < vector.size(); i++)
	{
		outfile << vector[i];
		outfile << '\n';
	}
	std::cout << "������ ��������� ����� ���������\n";
}

void RemakeString(std::string& string, std::vector<int32_t>& arr, std::string inword, std::string sentence)  //������ ���� �� ����������� � ����� ������ 
{                                                                                             //��� ��������������� ��������� ������� � ��������� �������� ����
	for (int i = 0; i < arr.size(); i++)
	{
		string.replace(arr[arr.size() - i - 1], inword.size(), sentence);
	}
}