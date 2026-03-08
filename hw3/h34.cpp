// An insertion sort algorithm on a collection of numbers using a built-in dynamic array
#include<iostream>
int main()
{
    int n;
    std::cout<<"Enter size n:";
    std::cin>>n;

    int*array= new int [n];
    for(int i=0; i<n;i++)
    {
        std::cin>>array[i];
    }

    for(int i=1; i<n;i++)
    {
        int current= array[i];
        int j=i-1;

        while(j>=0 && array[j]>current)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=current;
    }
    for(int i=0; i<n;i++)
    {
        std::cout<<array[i];
    }
    delete [] array;
}
