#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N;

    // ������ ���������� ��� ������
    cout << "������� ���������� ��� ������ (N): ";
    cin >> N;

    // �������� �� ������������ �����
    if (N <= 0) {
        cout << "���������� ��� ������ ������ ���� ������������� ������." << endl;
        return 1; // ���������� ��������� � �������
    }

    const double pricePerPair = 10500; // ���� �� ����
    const double pricePerBundle = 102500 / 12; // ���� �� ���� � ������
    const double pricePerBox = 1140000 / (12 * 12); // ���� �� ���� � �������

    if (N < 12) {
        // ���� ������ 12 ���
        if (N == 11) {
            cout << "�������� ������ ���� ������ (12 ���)." << endl;
            cout << "���� �� 12 ���: " << pricePerBundle * 12 << " ���." << endl;
        }
        else {
            cout << "�������� �������� ��������." << endl;
            cout << "���� �� " << N << " ���: " << pricePerPair * N << " ���." << endl;
        }
    }
    else {
        // ���� 12 ��� ������ ���
        int boxes = N / 12; // ���������� �������
        int remainingPairs = N % 12; // ���������� ����

        double totalCost = boxes * (12 * pricePerBox);

        if (remainingPairs > 0) {
            totalCost += remainingPairs * pricePerPair; // ��������� ���������� ���� ��������
            cout << "�������� ������ " << boxes << " ������� � " << remainingPairs << " ��� ��������." << endl;
        }
        else {
            cout << "�������� ������ " << boxes << " �������." << endl;
        }

        cout << "����� ���������: " << totalCost << " ���." << endl;
    }

    return 0; // ���������� ���������
}
