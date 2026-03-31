#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <cstdint>

void test_vector(std::size_t n) {
    std::vector<int> v;

    std::cout << "std::vector test\n";
    std::cout << "Tracking capacity growth:\n\n";

    std::size_t old_capacity = v.capacity();

    for (std::size_t i = 0; i < n; ++i) {
        v.push_back(static_cast<int>(i));

        if (v.capacity() != old_capacity) {
            std::cout << "After inserting element " << i
                      << ": size = " << std::setw(4) << v.size()
                      << ", old capacity = " << std::setw(4) << old_capacity
                      << ", new capacity = " << std::setw(4) << v.capacity();

            if (old_capacity != 0) {
                double factor =
                    static_cast<double>(v.capacity()) / old_capacity;
                std::cout << ", growth factor = "<< std::fixed << std::setprecision(2)<< factor;
            } else {
                std::cout << ", growth factor = undefined (first allocation)";
            }

            std::cout << '\n';
            old_capacity = v.capacity();
        }
    }

    std::cout << '\n';
}

void test_deque(std::size_t n) {
    std::deque<int> d;

    std::cout << "std::deque test\n";
    std::cout << "Tracking element addresses:\n\n";

    std::uintptr_t prev_address = 0;
    std::size_t block_size = 0;
    std::size_t block_number = 1;

    for (std::size_t i = 0; i < n; ++i) {
        d.push_back(static_cast<int>(i));

        std::uintptr_t current_address =
            reinterpret_cast<std::uintptr_t>(&d.back());

        std::cout << "Element " << std::setw(4) << i << ", value = " << std::setw(4) << d.back() << ", address = " << reinterpret_cast<void*>(current_address);

        if (i == 0) {
            block_size = 1;
            std::cout << "   start of block " << block_number;
        } else {
            std::uintptr_t diff = current_address - prev_address;

            if (diff == sizeof(int)) {
                ++block_size;
            } else {
                std::cout << "   new block starts, previous block had "<< block_size << " contiguous elements";
                ++block_number;
                block_size = 1;
            }
        }

        std::cout << '\n';
        prev_address = current_address;
    }

    std::cout << "Last block (" << block_number << ") has " << block_size << " contiguous elements\n\n";
}

int main() {
    test_vector(100);
    test_deque(300);

    return 0;
}