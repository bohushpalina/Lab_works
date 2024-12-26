#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N;

    // Запрос количества пар носков
    cout << "Введите количество пар носков (N): ";
    cin >> N;

    // Проверка на корректность ввода
    if (N <= 0) {
        cout << "Количество пар носков должно быть положительным числом." << endl;
        return 1; // Завершение программы с ошибкой
    }

    const double pricePerPair = 10500; // цена за пару
    const double pricePerBundle = 102500 / 12; // цена за пару в связке
    const double pricePerBox = 1140000 / (12 * 12); // цена за пару в коробке

    if (N < 12) {
        // Если меньше 12 пар
        if (N == 11) {
            cout << "Выгоднее купить одну связку (12 пар)." << endl;
            cout << "Цена за 12 пар: " << pricePerBundle * 12 << " руб." << endl;
        }
        else {
            cout << "Выгоднее покупать поштучно." << endl;
            cout << "Цена за " << N << " пар: " << pricePerPair * N << " руб." << endl;
        }
    }
    else {
        // Если 12 или больше пар
        int boxes = N / 12; // количество коробок
        int remainingPairs = N % 12; // оставшиеся пары

        double totalCost = boxes * (12 * pricePerBox);

        if (remainingPairs > 0) {
            totalCost += remainingPairs * pricePerPair; // добавляем оставшиеся пары поштучно
            cout << "Выгоднее купить " << boxes << " коробок и " << remainingPairs << " пар поштучно." << endl;
        }
        else {
            cout << "Выгоднее купить " << boxes << " коробок." << endl;
        }

        cout << "Общая стоимость: " << totalCost << " руб." << endl;
    }

    return 0; // Завершение программы
}
