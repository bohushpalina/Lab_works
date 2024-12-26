#include "Book.h"

Book::Book()
{
	std::cout << "Введите номер книги (УДК): ";
	std::cin >> udc;
	std::cin.ignore();  
	std::cout << "Введите название книги: ";
	std::cin >> title;  
	std::cout << "Введите год издания книги: ";
	std::cin >> year;
	std::cout << "Введите количество авторов: ";
	int32_t num_authors;
	std::cin >> num_authors;
	std::cin.ignore();  

	for (int i = 0; i < num_authors; ++i) {
		std::string last_name, first_name, middle_name;
		std::cout << "Введите фамилию автора " << i + 1 << ": ";
		std::getline(std::cin, last_name);

		std::cout << "Введите имя автора " << i + 1 << ": ";
		std::getline(std::cin, first_name);

		std::cout << "Введите отчество автора " << i + 1 << ": ";
		std::getline(std::cin, middle_name);
		Author author(last_name, first_name, middle_name);
		authors.push_back(author);
	}

	std::cout << "Книга успешно добавлена!\n";
}

Book::Book(const Book& rhs) : udc(rhs.udc), title(rhs.title), year(rhs.year), authors(rhs.authors)
{}

Book::Book(int32_t udc, const std::string& title, int32_t year) : udc(udc), title(title), year(year)
{
}

void Book::addAuthor(const Author& author)
{
	authors.push_back(author);
	std::sort(authors.begin(), authors.end(), [](Author a, Author b) { return a.compareAuthors(b); });
}

void Book::removeAuthor(const std::string& author)
{
	authors.erase(std::find(authors.begin(), authors.end(), author));
}

std::string Book::getTitle()
{
	return title;
}

Book::~Book()
{
}

bool Book::authorInBook(std::string& author)
{
	for (size_t i = 0; i < authors.size(); ++i)
	{
		if (authors[i].GetFullName() == author)
			return true;
	}
	return false;
}

Book& Book::operator=(const Book& rhs)
{
	udc = rhs.udc;
	title = rhs.title;
	year = rhs.year;
	authors = rhs.authors;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Book& book)
{
	out << "Номер книги: " << book.udc << "\nНазвание книги : " << book.title << "\nГод издания книги: " << book.year << '\n' << "Авторы книги:\n";
	bool flag = 0;
	for (size_t i = 0; i < book.authors.size(); ++i)
	{
		out << book.authors[i].GetFullName() << '\n';
		flag = 1;
	}
	if (!flag)
	{
		out << "Авторы отсутсвуют.\n";
	}
	return out;
}
