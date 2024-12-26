#include <iostream>
#include <cmath>

using namespace std;
//Нахождение всех пифагоровых троек до числа N
void findPythagoreanTriples(int N) {
    for (int K = 1; K <= N; ++K) {
        for (int L = K; L <= N; ++L) { // Начинаем с K, чтобы избежать дубликатов
            int M_squared = K * K + L * L;
            int M = static_cast<int>(sqrt(M_squared)); // Находим M

            // Проверяем, является ли M натуральным числом и не превышает ли N
            if (M * M == M_squared && M <= N) {
                cout << "(" << K << ", " << L << ", " << M << ")" << endl;
            }
        }
    }
}

int main() {
    int N;
    setlocale(LC_ALL, "Russian");
    cout << "Введите натуральное число N: ";
    cin >> N;

    cout << "Пифагоровы тройки чисел, не превышающие " << N << ":" << endl;
    findPythagoreanTriples(N);

    return 0;
}