#include "List.h"

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        List myList;
        myList.PushBack(10);
        myList.PushBack(20);
        myList.PushBack(30);
        myList.PushFront(5);
        myList.PushBack(36);
        myList.PushFront(534);
        myList.PushBack(38);
        myList.PushFront(234);

        std::cout << "��������� � ����������� ������: " << myList << '\n';
        myList.PopBack();
        std::cout << "�������� ���������� ��������: " << myList << '\n';
        myList.PopFront();
        std::cout << "�������� ������� ��������: " << myList << '\n';
        myList.Delete(20);
        std::cout << "�������� �������� �� ��������(20): " << myList << '\n';
        List copiedList(myList);
        std::cout << "������������� ����� ������: " << copiedList << '\n';
        List assignedList;
        assignedList = myList;
        std::cout << "����������� ������: " << assignedList << '\n';
        int comparisons = 0;
        bool found = myList.IsElementInList(10);
        std::cout << "���� ������� 10: " << (found ? "������" : "�� ������") << '\n';
        myList.ElementsPlusTwo();
        std::cout << "���������� ���� ��������� �� 2: " << myList << '\n';
        std::cout << "������ ���� ��������� ����� call-back �������: ";
        myList.ForEach([](const int& value) {std::cout << value << " ";});
        std::cout << '\n';

    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
    }

    return 0;
}