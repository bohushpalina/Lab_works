#include <fstream>
#include <map>
#include <windows.h>
#include "Book.h"

void CheckFile(std::ifstream&);
void EnterBooks(std::ifstream&, std::map < std::string, Book>&);
void PrintLibrary(std::map<std::string, Book>&);
void AddBook(std::map<std::string, Book>&);
void DeleteBook(std::map<std::string, Book>&);
void FindTitle(std::map<std::string, Book>&);
void FindAuthor(std::map<std::string, Book>&);

int main() {
	std::ifstream file ("Input.txt");
	std::map<std::string, Book> library;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		CheckFile(file);
		EnterBooks(file, library);
		PrintLibrary(library);
		AddBook(library);
		PrintLibrary(library);
		DeleteBook(library);
		PrintLibrary(library);
		FindTitle(library);
		FindAuthor(library);
		
	}
	catch (std::invalid_argument& error) { std::cout << "Ошибка: " << error.what(); }
	file.close();
	return 0;
}

void CheckFile(std::ifstream& file)
{
	if (!file)
		throw std::invalid_argument("Файл не существует");
	if (!file.is_open())
		throw std::invalid_argument("Файл не открыт");
	if (file.peek() == EOF)
		throw std::invalid_argument("Файл пустой");
}


void EnterBooks(std::ifstream& file, std::map < std::string, Book>& library)
{
	std::string string;
	std::string title, last_name, first_name, middle_name;
	while (std::getline(file, string))
	{
		std::string title;
		int32_t udc, year;
		size_t pos = 0;

		pos = string.find_first_of(' ');
		udc = std::stoi(string.substr(0, pos));
		string = string.substr(pos + 1);

		pos = string.find_first_of(' ');
		title = string.substr(0, pos);
		string = string.substr(pos + 1);

		pos = string.find_first_of(' ');
		year = std::stoi(string.substr(0, pos)); 
		string = string.substr(pos + 1);  

		Book book(udc, title, year);

		while (!string.empty()) {
			pos = string.find_first_of(' ');
			last_name = string.substr(0, pos);
			if (pos == std::string::npos)
				string = "";
			string = string.substr(pos + 1);

			pos = string.find_first_of(' ');
			first_name = string.substr(0, pos);
			if (pos == std::string::npos)
				string = "";
			string = string.substr(pos + 1);

			pos = string.find_first_of(' ');
			middle_name = string.substr(0, pos);
			if (pos == std::string::npos)
				string = "";
			string = string.substr(pos + 1);

			Author author(last_name, first_name, middle_name);
			book.addAuthor(author);
		}
		library.insert({ book.getTitle(), book });
	}
	std::cin.clear();
}

void PrintLibrary(std::map<std::string, Book>& library)
{
	std::cout << "Библиотека книг:\n";
	for (auto it_7 = library.begin(); it_7 != library.end(); ++it_7)
	{
		std::cout << it_7->second;
		std::cout << '\n';
	}
}

void AddBook(std::map<std::string, Book>& library)
{
	std::cout << "Реализация добавления книги: \n";
	Book added_book;
	library.insert({ added_book.getTitle(), added_book });
}

void DeleteBook(std::map<std::string, Book>& library)
{
	std::cout << "Реализация удаления книги: \n";
	std::cout << "Введите название книги, которую вы желаете удалить: ";
	std::string title_to_delete;
	std::cin >> title_to_delete;
	auto it_5 = library.find(title_to_delete);
	if (it_5 != library.end()) {
		library.erase(it_5);
		std::cout << "Книга удалена\n";
	}
	else {
		std::cout << "Книга с названием \"" << title_to_delete << "\" не найдена.\n";
	}
}

void FindTitle(std::map<std::string, Book>& library)
{
	std::string found_title;
	std::cout << "Введите название книги, которую вы хотите найти: ";
	std::cin >> found_title;
	auto it = library.find(found_title);
	if (it != library.end()) {
		std::cout << "Книга найдена: \n";
		std::cout << it->second << '\n';
	}
	else {
		std::cout << "Книга с названием \"" << found_title << "\" не найдена.\n";
	}
}


void FindAuthor(std::map<std::string, Book>& library)
{
	std::string found_author;
	std::cout << "Введите ФИО автора: ";
	std::cin.ignore();
	std::getline(std::cin, found_author);
	std::cin.clear();
	std::cout << "Книги данного автора: \n";
	bool flag = true;
	for (auto it_1 = library.begin(); it_1 != library.end(); ++it_1)
	{
		if (it_1->second.authorInBook(found_author))
		{
			std::cout << '\n';
			std::cout << it_1->second;
			flag = false;
		}
	}
	if (flag)
	{
		std::cout << "Отсутствуют\n";
	}
}