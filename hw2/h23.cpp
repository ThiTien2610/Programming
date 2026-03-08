// All three-digit Armstrong numbers
#include<iostream>
int main()
{
    std::cout<<"All three-digit Armstrong numbers:\n";
    for(int num=100; num <=999;num++)
    {
        int hundreds= num/100;
        int tens= (num/10)%10;
        int ones= num%10;

        int sum= hundreds*hundreds*hundreds+ tens*tens*tens+ones*ones*ones;

        if(sum==num)
        {
            std::cout<<num<<"\n";
        }
    }

}