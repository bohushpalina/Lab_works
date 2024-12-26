#include "List.h"

//конструктор без параметров, создающий пустой список;
List::List()
{
	Size = 0;
	first = nullptr;
}

List::List(const List& rhs)
{
	Size = rhs.Size;
	first = nullptr;
	Node* rhs_current = rhs.first;
	Node* current = first;
	while (rhs_current != nullptr)
	{
		Node* item = new Node{ rhs_current->info, nullptr };
		if (first == nullptr)
		{
			first = item;
			current = item;
		}
		else
		{
			current->next = item;
			current = current->next;
		}
		rhs_current = rhs_current->next;
	}
}


List::~List()   //деструктор
{
	Node* current = first;
	while (current != nullptr)
	{
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	first = nullptr;
}

//вставка нового элемента в конец списка;
void List::PushBack(int32_t info_in)
{
	Node* item = new Node{ info_in, nullptr };
	if (first == nullptr)
	{
		first = item;
	}
	else
	{
		Node* current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = item;
	}
	++Size;
}


void List::PushFront(int32_t info_in)
{
	Node* item = new Node{ info_in, nullptr };
	if (first == nullptr)
	{
		first = item;
	}
	else
	{
		item->next = first;
		first = item;
	}
	++Size;
}


int32_t List::GetSize()
{
	return Size;
}

//удаление элемента из конца списка;
void List::PopBack()
{
	if (first == nullptr)
		throw std::invalid_argument("Список пуст!");
	if (Size == 1)
	{
		delete first;
		first = nullptr;
	}
	else
	{
		Node* current = first;
		Node* previous = current;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		delete current;
		previous->next = nullptr;
	}
	--Size;
}

//удаление элемента из конца списка;
void List::PopFront()
{
	if (first == nullptr)
		throw std::invalid_argument("Список пуст!");
	Node* pointer = first->next;
	first = new Node;
	first = pointer;
	--Size;
}

//удаление элемента по значению
void List::Delete(int32_t info_in)
{
	if (first == nullptr)
		throw std::invalid_argument("Список пуст!");
	Node* current = first;
	Node* previous = nullptr;
	while (current != nullptr)
	{
		if (current->info == info_in)
		{
			if (previous == nullptr)
			{
				Node* pointer = first->next;
				delete first;
				first = pointer;
			}
			else
			{
				previous->next = current -> next;
				delete current;
			}
			--Size;
			return;
		}
		previous = current;
		current = current->next;
	}
}

List& List::operator=(const List& rhs)
{
	if (this == &rhs)
		return *this;
	Node* current = first;  //очищение памяти
	while (current != nullptr)
	{
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	Size = rhs.Size;  //присваивание
	first = nullptr;
	Node* rhs_current = rhs.first;
	current = first;
	while (rhs_current != nullptr)
	{
		Node* item = new Node{ rhs_current->info, nullptr };
		if (first == nullptr)
		{
			first = item;
			current = item;
		}
		else
		{
			current->next = item;
			current = item;
		}
		rhs_current = rhs_current->next;
	}
	return *this;
}

bool List::IsElementInList(const int32_t& info_in)
{
	int32_t count = 0;
	Node* current = first;
	while (current != nullptr)
	{
		++count;
		if (current->info == info_in)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

void List::ElementsPlusTwo()
{
	Node* current = first;
	while (current != nullptr)
	{
		current->info = current->info + 2;
		current = current->next;
	}
}

void List::ForEach(std::function<void(const int32_t&)> func)
{
	int32_t count = 1;
	Node* current = first;
	while (current != nullptr)
	{
		func(current->info);
		current = current->next;
		++count;
	}
}

std::ostream& operator<<(std::ostream& out, const List& list)
{
	bool flag = false;
	List::Node* current = list.first;
	while (current != nullptr)
	{
		if (!flag)
		{
			out << current->info;
			flag = true;
		}
		else
		{
			out << ' ' << current->info;
		}
		current = current->next;
	}
	return out;
}
