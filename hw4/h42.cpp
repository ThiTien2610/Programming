// Bubble sort algorithm for a standard container using a separate function

#include<iostream>
#include<vector>

void bubblesort(std::vector<int> &arr)
{
    int n=arr.size();
    for(int i=0; i<n-1;++i)
    {
        for(int j=0; j<n-1-i;++j)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
            }

        }
    }

}

int main() 
{
    int n;
    std::cout << "Enter n:" ;
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    for (int x : arr) 
    {
        std::cout << x << " ";
    }

    bubblesort(arr);

    std::cout << "Ordered array: "<< '\n';
    for (int x : arr) 
    {
        std::cout << x << " "<< '\n';
    }
    return 0;
}