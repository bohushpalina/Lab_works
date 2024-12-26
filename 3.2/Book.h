#ifndef _BOOK_
#define _BOOK_
#include "Author.h";
#include <vector>
#include <algorithm>

class Book
{
private:
    int32_t udc; // Номер УДК
    std::string title;
    int32_t year;
    std::vector<Author> authors;
public:
    Book();
    Book(const Book&);
    Book(int32_t, const std::string&, int32_t);
    void addAuthor(const Author&);
    void removeAuthor(const std::string&);
    std::string getTitle();
    ~Book();
    bool authorInBook(std::string&);
    friend std::ostream& operator<<(std::ostream&, Book&);
    Book& operator=(const Book&);
};


#endif
