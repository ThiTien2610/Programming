#include <iostream>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::set<std::string> words;
    std::string word;

    for (int i = 0; i < n; i++) {
        std::cin >> word;
        words.insert(word);
    }

    for (const std::string& w : words) {
        std::cout << w << '\n';
    }

    return 0;
}