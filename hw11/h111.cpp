// Implement a compile-time algorithm for calculating pi. 
// Use a constexpr function and static assertions. 
// Use any convenient series-based algorithm, such as the Leibniz series.

#include<cmath>
#include<iostream>

constexpr double Leibniz_series(int n)
{
    double sum =0.0;
    for (int i=0;i<n;++i)
    {
        sum+= ((i %2 ==0) ? 1.0 : -1.0) /(2*i+1);
    }
    return 4.0 *sum;
}

static_assert (std::abs(Leibniz_series(2000)- 3.14159)<0.01, "Pi calculation is incorrect!");

int main ()
{
    constexpr double pi_value = Leibniz_series(2000);
    std::cout << "Pi = "<< pi_value << '\n';
}