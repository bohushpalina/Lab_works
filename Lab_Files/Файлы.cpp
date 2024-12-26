#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void CheckFile(std::ifstream&);
void Output(int32_t&, std::string&);
void FindMax(std::vector <std::string>&, std::vector<int32_t>&);
void CheckWord(std::string, std::vector <std::string>&, std::vector<int32_t>&);
void ReadFile(std::ifstream&, std::vector <std::string>&, std::vector<int32_t>&);

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::string> vect;
	std::vector <int32_t > count;
	std::ifstream file("Input.txt");
	try
	{
		CheckFile(file);
		ReadFile(file, vect, count);
		FindMax(vect, count);
	}
	catch (const char* str) { std::cout << str; }
	file.close();
	return 0;
}

void CheckFile(std::ifstream& ifile) { //проверка файлов
	if (!ifile)
		throw "Файл не существует\n";
	if (!ifile.is_open())
		throw "Файл не открылся\n";
	if (ifile.peek() == EOF)
		throw "Входной файл пуст\n";
}

void Output(int32_t& max, std::string& max_str) {
	std::cout << "Первое наиболее встречаемое слово: " << max_str << '\n';
	/*std::cout << "Первое наиболее встречаемое слово: " << max_str << "\nКоличество раз: " << max << "\n";*/
}

void FindMax(std::vector <std::string>& vect, std::vector<int32_t>& count) //нахождение наиболее встречаемого и вывод
{
	int32_t max = 0;
	std::string max_str;
	for (int32_t i = 0; i < count.size(); i++)
	{
		if (max < count[i])
		{
			max = count[i];
			max_str = vect[i];
		}
	}
	Output(max, max_str);
}

void CheckWord(std::string word, std::vector <std::string>& vect, std::vector<int32_t>& count) { //проверка данного слова на вхождения в файл
	if (std::find(vect.begin(), vect.end(), word) == vect.end())
	{
		vect.push_back(word);
		count.push_back(1);
	}
	else
	{
		int32_t pos = -1;
		int32_t  i = -1;
		while (pos == -1)
		{
			i++;
			if (vect[i] == word)
				pos = i;
		}
		count[i] = count[i] + 1;
	}
}

void ReadFile(std::ifstream& file, std::vector <std::string>& vect, std::vector<int32_t>& count) { //чтение всех строк файла
	std::string string, delims = " ", word;
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
			CheckWord(word, vect, count); //проверка данного слова на вхождения в файл
			BegInd = string.find_first_not_of(delims, EndInd);
		}
	}

}