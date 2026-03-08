// The maximum and minimum values ​​of a collection of numbers using a built-in static array
#include<iostream>
int main()
{
    int n=0;
    std::cout<<"How many numbers?";
    std::cin>>n;

    int array[100]{};
    std::cout<<"Enter " << n <<" numbers: ";
    for(int i=0; i<n;i++)
       {
        std::cin>> array[i];
       } 
    int max=array[0], min= array[0];
    for(int i=1; i<n;i++)
       {
        if (array[i]>max)
            max=array[i];
        if (array[i]<min)
            min =array[i];
       }
    std::cout<<"Max:"<<max<<"\n";
    std::cout<<"Min:"<<min;

}