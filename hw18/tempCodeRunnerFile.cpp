#include <iostream>
#include <vector>
#include <unordered_set>

int firstRepeated(const std::vector<int>& arr) {
    std::unordered_set<int> seen;

    for (int x : arr) {
        if (seen.count(x)) {
            return x;
        }
        seen.insert(x);
    }

    return -1;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << firstRepeated(arr) << '\n';

    return 0;
}