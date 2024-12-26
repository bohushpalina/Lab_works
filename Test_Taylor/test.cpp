#include "pch.h"
#include "C:\Users\Polina\Лаб_2\CountSum.cpp"
#include <cmath>
#include "CountSum.h"

// Тесты
TEST(CountSumTest, ValidInput) {
    ASSERT_NEAR(CountSum(0.5, 2), log(0.5 + 1), pow(10, -1));
    ASSERT_NEAR(CountSum(0.1, 3), log(0.1 + 1), pow(10, -2));
    ASSERT_NEAR(CountSum(-0.5, 2), log(-0.5 + 1), pow(10, -1));
    ASSERT_NEAR(CountSum(0.01, 2), log(0.01 + 1), pow(10, -1));
    ASSERT_NEAR(CountSum(0.99, 3), log(0.99 + 1), pow(10, -2));
    ASSERT_NEAR(CountSum(0, 5), log(0 + 1), pow(10, -4));
    ASSERT_NEAR(CountSum(0.5, 10), log(0.5 + 1), pow(10, -9));
    ASSERT_NEAR(CountSum(0.99, 7), log(0.99 + 1), pow(10, -6));
}



TEST(CountSumTest, InvalidInput) {
    ASSERT_NEAR(CountSum(-2.0, 1), std::invalid_argument);
    ASSERT_NEAR(CountSum(2.0, 1), std::invalid_argument);
    ASSERT_NEAR(CountSum(0.5, 0), std::invalid_argument);
    ASSERT_NEAR(CountSum(-1, 1), std::invalid_argument);
}
