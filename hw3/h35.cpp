// All prime numbers from 1 to 100 using the standard container std::vector
#include<iostream>
#include<vector>
int main()
{
    std::vector<double>vector;
    std::cout << "Prime numbers between 1 to 100 are:\n";
    for(int i = 2; i <= 100; i++) 
    {
        bool isprime = true;
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        
        if(isprime)
            vector.push_back(i); 
    }

    for(int i = 0; i < vector.size(); i++) 
    {
        std::cout << vector[i] << std::endl;
    }
}

