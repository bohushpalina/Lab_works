#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <functional>
//����� ��� ������ � ������?

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
	List(); //����������� ��� ����������, ��������� ������ ������;
	List(const List&); //����������� �����������;
	~List(); // ����������;
	void PushBack(int32_t); // ������� ������ �������� � ����� ������;
	void PushFront(int32_t); // ������� ������ �������� � ������ ������;
	int32_t GetSize(); 
	void PopBack(); //�������� ���������� �������� ������;
	void PopFront(); //�������� ������� �������� ������;
	void Delete(int32_t); //
	List& operator=(const List&); //���������� ��������� ������������
	friend std::ostream& operator<<(std::ostream&, const List&); //
	bool IsElementInList(const int32_t&); //����� �������� �� �������� � ��������� ����� ���������, ����������� � �������� ������;
	void ElementsPlusTwo(); //�������� ������ � ���������� ���� ��������; (+2)
	void ForEach(std::function<void(const int32_t&)>); //�������� ������ � ������� callback-�������, ������� �� �������� ���������� �������� ()

};

#endif