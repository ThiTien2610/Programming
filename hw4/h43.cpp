// Checking whether a standard container is sorted in ascending order using a separate function
#include<iostream>
#include<vector>

bool issorted(const std::vector<int> &arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false; 
        }
    }
    return true; 
}

int main() 
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
    }

    if (issorted(arr))
    {
        std::cout << "Array is sorted in ascending order." << '\n';
    } 
    else 
    {
        std::cout << "Array is not sorted in ascending order." << '\n';
    }

    return 0;
}