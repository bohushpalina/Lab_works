#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>

void CheckDel(std::string);
void InputDelims(std::string&);
void InputString(std::string&);
void FindPalindrom(std::string, int32_t&, std::string);
void CheckPalindrom(std::string&, int32_t&);
void ToLowerCase(std::string&);
void CheckAndPrintPalindrom(std::string, int32_t, bool&);

int main() {
	try 
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::string str, del;
		int32_t max_length = 0;
		InputDelims(del);
		InputString(str);
		int32_t max_size = 0;
		FindPalindrom(str, max_size, del);
	}
	catch (const char* mis) { std::cout << mis; }

	return 0;
}

void InputDelims(std::string& delim) { // ввод разделителя
	std::cout << "Введите разделитель слов: ";
	getline(std::cin, delim);
	/*CheckDel(delim);*/
}


void InputString(std::string& str) { //ввод строки
	std::cout << "Введите строку: " << '\n';
	getline(std::cin, str);
	if (str.size() == 0)
		throw "Строка пустая!";

}

void FindPalindrom(std::string str, int32_t& max_size, std::string del) {
	size_t BegInd, EndInd;
	std::string word;
	BegInd = str.find_first_not_of(del);
	bool dop = 0;
	while (BegInd != std::string::npos)
	{
		EndInd = str.find_first_of(del, BegInd);
		if (EndInd == std::string::npos)
			EndInd = str.length();
		word = str.substr(BegInd, EndInd - BegInd); //делим строку на слова с разделителем
		// std::cout << "Слово - " << word << '\n';
		CheckPalindrom(word, max_size); 
		BegInd = str.find_first_not_of(del, EndInd);
	}
	//Следующий этап: после нахождения макимального размера возможных палиндромов, напечатать все таковые
	if (max_size == 0)
		throw "Палиндромов в строке нет!";
	else
	{
		BegInd = str.find_first_not_of(del); //повторно прогоняем все слова
		while (BegInd != std::string::npos)
		{
			EndInd = str.find_first_of(del, BegInd);
			if (EndInd == std::string::npos)
				EndInd = str.length();
			word = str.substr(BegInd, EndInd - BegInd);
			CheckAndPrintPalindrom(word, max_size, dop);
			BegInd = str.find_first_not_of(del, EndInd);
		}
	}
}

void CheckPalindrom(std::string& word, int32_t& max_size) { //проверяем, палиндром ли, если да, то вводим макимальное количество символов
	bool ex = 1;
	ToLowerCase(word);
	for (int32_t i = 0; i < word.length() / 2; i++)
	{
		if (word[i] != word[word.length() - 1 - i])
			ex = 0;
	}
	if (ex == 1 && max_size < word.length())
		max_size = word.length();

}

void ToLowerCase(std::string& word) { //приводим слово к нижнему регистру, библиотека cctype
	for (int32_t i = 0; i < word.size(); i++)
		word[i] = std::tolower(word[i]);
}

void CheckAndPrintPalindrom(std::string word, int32_t max_size, bool& dop) { // то же, что и CheckPalindrom, но в случае пройденной проверки,
	bool ex = 1;                                                                                                        // если палиндром наибольший, выводим на экран
	std::string word_copy = word;
	ToLowerCase(word);
	for (int32_t i = 0; i < word.length() / 2; i++)
	{
		if (word[i] != word[word.length() - 1 - i])
			ex = 0;
	}
	if (ex == 1 && max_size == word.length())
	{
		if (dop != 0)
		{
			std::cout << ", ";
			std::cout << word_copy;
		}
		else
		{
			std::cout << word_copy;
			dop = 1;
		}
	}
}