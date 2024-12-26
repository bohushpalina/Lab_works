#include <iostream>
#include "Fractions.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Fraction f1(-5, 2); // 1/2
    Fraction f2(3, 2); // 3/4
    Fraction f3(5, 2);    // 5/7

    std::cout << "f1: " << f1 << '\n';
    std::cout << "f2: " << f2 << '\n';
    std::cout << "f3: " << f3 << '\n';

    Fraction sum = f1 + f2;
    std::cout << "f1 + f2 = " << sum << '\n';

    Fraction sum_2 = f1 + 2;
    std::cout << "f1 + 2 = " << sum_2 << '\n';

    Fraction prod = f1 * f2;
    std::cout << "f1 * f2 = " << prod << '\n';

    Fraction dif = f2 - f1;
    std::cout << "f2 - f1 = " << dif << '\n';
    Fraction div = f2 / f1;
    std::cout << "f2 / f1 = " << div << '\n';

    if (f1 < f2) {
        std::cout << "f1 меньше f2" << '\n';
    }
    else {
        std::cout << "f1 не меньше f2" << '\n';
    }

    if (1 > f1) {
        std::cout << "f1 меньше 1" << '\n';
    }
    else {
        std::cout << "f1 не меньше 1" << '\n';
    }

    ++f3;
    std::cout << "После префиксного инкремента f3: " << f3 << '\n';

    Fraction temp = f3++; 
    std::cout << "После постфиксного инкремента f3: " << f3 << ", предыдущее значение: " << temp << '\n';

    --f3;
    std::cout << "После префиксного декремента f3: " << f3 << '\n';

    temp = f3--;
    std::cout << "После постфиксного декремента f3: " << f3 << ", предыдущее значение: " << temp << '\n';

    Fraction entered;
    std::cin >> entered;
    std::cout << "Введенная дробь: " << entered << '\n';

    entered += f3;
    std::cout << "entered += f3: " << entered << '\n';

    entered -= f3;
    std::cout << "entered -= f3: " << entered << '\n';

    entered *= f3;
    std::cout << "entered *= f3: " << entered << '\n';

    entered /= f3;
    std::cout << "entered /= f3: " << entered << '\n';

    return 0;
}
