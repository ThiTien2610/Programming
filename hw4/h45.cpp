// Counting the number of occurrences of a given character in a standard string using a separate function

#include <iostream>
#include <string>


int count_char(const std::string &text, char letter) 
{
    int count = 0;

    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == letter) 
        {
            count++;
        }
    }

    return count;
}
int main() 
{
    std::string s;
    char c;

    std::cout << "Enter word: ";
    std::cin>> s;

    std::cout << "Which letters do you want to count?";
    std::cin >> c;

    int result = count_char(s, c);

    std::cout << "Letter '" << c << "' exits " << result << " times." << '\n';

    return 0;
}