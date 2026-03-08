// The greatest common divisor of two natural numbers 
#include<iostream>
int main()
{
    int a,b;
    std::cout<<"Enter a:";
    std::cin>>a;
    std::cout<<"Enter b:";
    std::cin>>b;

    int c;
    while (b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    std::cout<<"GCD:"<<a;
}