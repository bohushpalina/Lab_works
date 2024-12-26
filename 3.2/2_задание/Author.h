#ifndef _AUTHOR_
#define _AUTHOR_

#include <iostream>
#include <string>

class Author
{
private:
	std::string first_name;
	std::string last_name;
	std::string middle_name;
public:
	Author(std::string = "No last name", std::string = "No first name", std::string = "No middle name");
	std::string GetFullName();
	~Author();
	bool compareAuthors(const Author& b);
	bool operator==(const Author&);
};


#endif
