// Check if a number is prime
#include<iostream>
int main()
{
        int a;
        std::cout<<"Enter a, a>0: ";
        std::cin>>a;
        if (a<=0)
        {
            std::cout<<a<<"is not prime \n";
    
        }
        else
        {
            bool isprime= true;
            for (int i=2;i<a;i++)
            {
                if (a%i ==0)
                {
                    isprime =false;
                    break;
                }
            }

        if (isprime)
            std::cout<< a<<" is a prime \n";
        else
            std::cout<<a<<" is not a prime \n";
        }

}

