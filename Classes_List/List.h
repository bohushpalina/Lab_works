#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <functional>
//какой тип данных у списка?

class List
{
private:

	struct Node
	{
		int32_t info;
		Node* next;
	};
	Node* first;
	int32_t Size;

public:
	List(); //конструктор без параметров, создающий пустой список;
	List(const List&); //конструктор копирования;
	~List(); // деструктор;
	void PushBack(int32_t); // вставка нового элемента в конец списка;
	void PushFront(int32_t); // вставка нового элемента в начало списка;
	int32_t GetSize(); 
	void PopBack(); //удаление последнего элемента списка;
	void PopFront(); //удаление первого элемента списка;
	void Delete(int32_t); //
	List& operator=(const List&); //перегрузка оператора присваивания
	friend std::ostream& operator<<(std::ostream&, const List&); //
	bool IsElementInList(const int32_t&); //поиск элемента по значению с подсчетом числа сравнений, выполненных в процессе поиска;
	void ElementsPlusTwo(); //просмотр списка с изменением всех значений; (+2)
	void ForEach(std::function<void(const int32_t&)>); //просмотр списка с вызовом callback-функции, которая не изменяет хранящееся значение ()

};

#endif