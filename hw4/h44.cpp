//  Reversing the order of elements in a standard container using a separate function
#include <iostream>
#include <vector>

void reverse_vector(std::vector<int> &arr) 
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j) 
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
}

int main() 
{
    int n;
    std::cout << "How many numbers? ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    reverse_vector(arr);

    std::cout << "Array is reversed: ";
    for (int x : arr) 
    {
        std::cout << x << " ";
    }

    //std::cout <<'\n';
    return 0;
}