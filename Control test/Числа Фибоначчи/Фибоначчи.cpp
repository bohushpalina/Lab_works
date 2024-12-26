#include <iostream>
#include <cmath>

using namespace std;
//���������� ���� ����������� ����� �� ����� N
void findPythagoreanTriples(int N) {
    for (int K = 1; K <= N; ++K) {
        for (int L = K; L <= N; ++L) { // �������� � K, ����� �������� ����������
            int M_squared = K * K + L * L;
            int M = static_cast<int>(sqrt(M_squared)); // ������� M

            // ���������, �������� �� M ����������� ������ � �� ��������� �� N
            if (M * M == M_squared && M <= N) {
                cout << "(" << K << ", " << L << ", " << M << ")" << endl;
            }
        }
    }
}

int main() {
    int N;
    setlocale(LC_ALL, "Russian");
    cout << "������� ����������� ����� N: ";
    cin >> N;

    cout << "���������� ������ �����, �� ����������� " << N << ":" << endl;
    findPythagoreanTriples(N);

    return 0;
}