#include "Author.h"


Author::Author(std::string last, std::string first, std::string middle)
{
	first_name = first;
	last_name = last;
	middle_name = middle;
}

std::string Author::GetFullName()
{
	return std::string(last_name + " " + first_name + " " + middle_name);
}

Author::~Author()
{
}

bool Author::compareAuthors(const Author& rhs)
{
	{
		if (last_name != rhs.last_name)
			return last_name < rhs.last_name; // ������� ���������� �������
		if (first_name != rhs.first_name)
			return first_name < rhs.first_name; // ���� ������� ���������, ���������� �����
		return middle_name < rhs.middle_name; // ���� � ����� ���������, ���������� ��������
	}
}

bool Author::operator==(const Author& rhs)
{
	return (first_name == rhs.first_name && last_name == rhs.last_name && middle_name == rhs.middle_name);
}
