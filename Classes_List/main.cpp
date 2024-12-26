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

        std::cout << "Созданный и заполненный список: " << myList << '\n';
        myList.PopBack();
        std::cout << "Удаление последнего элемента: " << myList << '\n';
        myList.PopFront();
        std::cout << "Удаление первого элемента: " << myList << '\n';
        myList.Delete(20);
        std::cout << "Удаление элемента по значению(20): " << myList << '\n';
        List copiedList(myList);
        std::cout << "Скопированный новый список: " << copiedList << '\n';
        List assignedList;
        assignedList = myList;
        std::cout << "Присвоенный список: " << assignedList << '\n';
        int comparisons = 0;
        bool found = myList.IsElementInList(10);
        std::cout << "Ищем элемент 10: " << (found ? "Найден" : "Не найден") << '\n';
        myList.ElementsPlusTwo();
        std::cout << "Увеличение всех элементов на 2: " << myList << '\n';
        std::cout << "Печать всех элементов через call-back функцию: ";
        myList.ForEach([](const int& value) {std::cout << value << " ";});
        std::cout << '\n';

    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
    }

    return 0;
}