// Classify input characters into multiple classes using switch statement
#include <iostream>
#include <cctype>  

int main() 
{
    char character;
    std::cout << "Enter a character: ";
    std::cin >> character;

    char lower = tolower(character);
    switch (lower) 
    {
        case 'a':
        case 'o':
        case 'e':
        case 'u':
        case 'i':
        std::cout << character << " is a vowel\n";
        break;

        case '0': 
        case '1': 
        case '2': 
        case '3': 
        case '4':
        case '5': 
        case '6': 
        case '7': 
        case '8': 
        case '9':
        std::cout << character << " is a digit\n";
        break;

        default:
            if (isalpha(character)) 
            {
                std::cout << character << " is a consonant\n";
            } else 
            {
                std::cout << character << " is a special character\n";
            }
    }
}