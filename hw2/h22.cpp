// The N-th Fibonacci number
#include<iostream>
int main()
{
    int n;
    std::cout<<"Enter n, n>0:";
    std::cin >>n;
    if (n<0)
        std::cout<<"Enter n again!";
    else 
    {
        if(n==0)
            std::cout<<"0 \n";
        if (n==1)
            std::cout<<"1 \n";
        if (n>=2) 
        {
            int c, a=0, b=1;
            for (int i=2; i<=n; i++)
            {
                c=a+b;
                a=b;
                b=c;
            }
            std::cout<<c<<'\n' ;
        }
        
    }
    
}

