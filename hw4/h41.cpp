// Calculating the least common multiple using a separate function

#include <iostream>

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp= b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b)
{
    return std::abs(a * b) / gcd(a, b);
}

int main() 
{
    int x, y;
    std::cout << "Enter 2 numbers: ";
    std::cin >> x >> y;

    std::cout << "LCM " << x << " and " << y << " is: " << lcm(x, y)<<"\n";
    return 0;
}