#include <iostream>
#include "08.13.hpp"

Integer power(Integer base, unsigned int exponent)
{
    Integer result = 1;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result *= base;
        }

        base *= base;
        exponent /= 2;
    }

    return result;
}

int main()
{
    Integer x;
    unsigned int n;
    std::cin >> x >> n;
    std::cout << power(x, n) << '\n';
    return 0;
}