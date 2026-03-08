// Enhance your previous implementation of the bubble sort algorithm using function templates.
// Demonstrate the feasibility of using the template with different types

#include<iostream>
#include<vector>
#include<string>
template <typename T>
void bubblesort(std::vector<T> &arr)
{
    int n=arr.size();
    for(int i=0; i<n-1;++i)
    {
        for(int j=0; j<n-1-i;++j)
        {
            if (arr[j]>arr[j+1])
            {
                T temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
            }

        }
    }
}
template<typename P>
void printVector(const std::vector<P> &arr)
{
    for (const P&x :arr)
    {
        std::cout<<x<<" ";
    }
    std:: cout<<"\n";
}
int main()
{
    std::vector<double> doubleVector={2.6, 1.0, 2.5, 9.8};
    std::cout<<" Original double array: ";
    printVector(doubleVector);
    bubblesort(doubleVector);
    std::cout<< "Sorted double array: ";
    printVector(doubleVector);

    std::vector<std::string> stringVector={"ball", "book", "pen"};
    std::cout<<" Original string array: ";
    printVector(stringVector);
    bubblesort(stringVector);
    std::cout<< "Sorted string array: ";
    printVector(stringVector);

    return 0;
}