// Factorial of a number
#include<iostream>
int main()
{
    int n=0,a=1;
    std::cout<<"Enter n:";
    std::cin>>n;

    for(int i=1;i<=n;i++)
        a*=i;
    std::cout<<n<<"!="<<a<<std::endl;

}