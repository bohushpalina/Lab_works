//#include <iostream>
//#include <string>
//#include <vector>
//
//int main() {
//    int32_t n, k, a;
//    std::cin >> n >> k;
//    int64_t first_sum = 0, second_sum = 0;
//    std::vector<int32_t> vector;
//
//    for (int32_t i = 0; i < n; i++) {
//        std::cin >> a;
//        vector.push_back(a);
//        first_sum += a;
//    }
//
//    for (int32_t i = 0; i < k; i++) {
//        int32_t max_pos = -1, max = 0;
//
//        for (int32_t j = 0; j < n; j++) {
//            std::string number = std::to_string(vector[j]);
//
//            if (number.find_first_not_of("9") != std::string::npos) {
//                int32_t g = 0;
//                while (g < number.length() && number[g] == '9') {
//                    g++;
//                }
//                if (g < number.length()) { // Проверка на выход за пределы
//                    number[g] = '9';
//                    try {
//                        int32_t new_value = std::stoi(number);
//                        if (new_value - vector[j] > max) {
//                            max = new_value - vector[j];
//                            max_pos = j;
//                        }
//                    }
//                    catch (const std::invalid_argument& e) {
//                        // Обработка ошибки преобразования
//                    }
//                    catch (const std::out_of_range& e) {
//                        // Обработка ошибки переполнения
//                    }
//                }
//            }
//        }
//
//        if (max_pos != -1) {
//            second_sum += max;
//            vector[max_pos] += max;
//        }
//    }
//
//    std::cout << second_sum;
//
//    return 0;
//}
//

//#include <iostream>
//#include <string>
//
//bool CheckNumber(int64_t num, int32_t size) {
//	int32_t new_dig, dig;
//	for (int32_t i = 0; i < size - 1; i++)
//	{
//		dig = num % 10;
//		num = num / 10;
//		new_dig = num % 10;
//		if (new_dig != dig)
//			return 0;
//	}
//	return 1;
//}
//
//int main() {
//	int64_t l, m;
//	std::cin >> l >> m;
//	int64_t num = l + 1;
//	int32_t count = 0;
//	while (num < m)
//	{
//		if (CheckNumber(num, std::to_string(num).length()))
//			count++;
//		num++;
//	}
//	std::cout << count;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//int main() {
//	int32_t count, not_right =0, a;
//	std::cin >> count;
//	int32_t chet = -1, nechet = -1;
//	for (int32_t i = 0; i < count; i++)
//	{
//		std::cin >> a;
//		if (a % 2 == 0 && i % 2 != 0)
//		{
//			not_right++;
//			chet = i + 1;
//		}
//		else if (i % 2 == 0 && a % 2 != 0)
//		{
//			not_right++;
//			nechet = i + 1;
//		}
//	}
//	if (nechet > -1 && chet > -1 && not_right == 2)
//	{
//		if (chet < nechet)
//			std::cout << chet << ' ' << nechet;
//		else
//			std::cout << chet << ' ' << nechet;
//	}
//	else
//		std::cout << "-1 -1";
//	return 0;
//}

#include <iostream>
#include <cmath>

int main() {
    int32_t a, b;
    std::cin >> a >> b;
    std::cout << pow(a, b);
    return 0;
}