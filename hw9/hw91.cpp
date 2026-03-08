// Implement algorithms for calculating the maximum and minimum values, sum, and average of a batch of double arguments.Use variadic function templates
// Use recursive instantiation of variadic function templates when calculating the maximum and minimum values ​​of a batch.
// Use fold expressions when calculating the sum and average of a batch.
// Use the sizeof... operator to determine the number of arguments when calculating the average of a batch.
// Assume that the batch contains only double arguments, and that their number is nonzero.

#include<iostream>

double minimum (double a, double b)
{
    return a<b ? a:b;
}
template < typename... Args>
double minimum(double a, Args... args)
{
    return minimum(a, minimum(args...));
}

double maximum (double a, double b)
{
    return a>b ? a:b;
}
template < typename... Args>
double maximum(double a, Args... args)
{
    return maximum(a, maximum(args...));
}

template<typename... Args>
double sum(Args... args)
{
    return (... + args);
}

template<typename... Args>
double average(Args... args)
{
    return (args+...)/ static_cast<double>(sizeof...(args));
}

int main()
{
    std::cout<< "Minimum = "<<minimum(5.6,8.9,7.6,2.3)<< "\n";
    std::cout<< "Maximum = "<<maximum(5.6,8.9,7.6,2.3)<< "\n";
    std::cout<< "Sum = "<<sum(5.6,8.9,7.6,2.3)<< "\n";
    std::cout<< "Average = "<<average(5.6,8.9,7.6,2.3)<< "\n";
}