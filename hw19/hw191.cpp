// Enhace of hw34.cpp

#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

template <typename T, typename Compare = std::less<T>>
void insertionSort(T* array, int n, Compare comp = Compare())
{
    for (int i = 1; i < n; i++)
    {
        T current = array[i];
        int j = i - 1;

        while (j >= 0 && comp(current, array[j]))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

template <typename T>
void printArray(T* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }
    cout << '\n';
}

// Custom function object
struct AbsCompare
{
    bool operator()(int a, int b) const
    {
        if (abs(a) != abs(b))
            return abs(a) < abs(b);
        return a < b;
    }
};

int main()
{
    int a1[] = {5, 2, 8, 1, 4};
    int n1 = 5;

  
    insertionSort(a1, n1, std::less<int>());
    cout << "Ascending (std::less): ";
    printArray(a1, n1);

    int a2[] = {5, 2, 8, 1, 4};
    int n2 = 5;

    
    insertionSort(a2, n2, std::greater<int>());
    cout << "Descending (std::greater): ";
    printArray(a2, n2);

    int a3[] = {5, -2, 8, -1, 4};
    int n3 = 5;

    
    insertionSort(a3, n3, AbsCompare());
    cout << "By absolute value (custom functor): ";
    printArray(a3, n3);

    int a4[] = {5, 2, 8, 1, 4};
    int n4 = 5;

    insertionSort(a4, n4, [](int x, int y)
    {
        if ((x % 2 == 0) != (y % 2 == 0))
            return x % 2 == 0;   
        return x < y;            
    });

    cout << "Even first (lambda): ";
    printArray(a4, n4);

    return 0;
}