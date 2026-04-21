#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <ranges>
#include <string>
#include <vector>

namespace rng = std::ranges;

template <typename T>
void print_vector(const std::vector<T>& v, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

template <typename Range, typename Pred, typename Func>
auto transform_if(const Range& r, Pred pred, Func func) {
    using InType = std::ranges::range_value_t<Range>;
    using OutType = decltype(func(std::declval<InType>()));

    std::vector<InType> filtered;
    rng::copy_if(r, std::back_inserter(filtered), pred);

    std::vector<OutType> result;
    result.reserve(filtered.size());
    rng::transform(filtered, std::back_inserter(result), func);

    return result;
}

template <typename T>
double mae(const std::vector<T>& y_true, const std::vector<T>& y_pred) {
    assert(y_true.size() == y_pred.size());
    assert(!y_true.empty());

    double sum = std::transform_reduce(
        y_true.begin(), y_true.end(),
        y_pred.begin(),
        0.0,
        std::plus<>(),
        [](const auto& a, const auto& b) {
            return std::abs(static_cast<double>(a) - static_cast<double>(b));
        }
    );

    return sum / y_true.size();
}

template <typename T>
double rmse(const std::vector<T>& y_true, const std::vector<T>& y_pred) {
    assert(y_true.size() == y_pred.size());
    assert(!y_true.empty());

    double sum_sq = std::transform_reduce(
        y_true.begin(), y_true.end(),
        y_pred.begin(),
        0.0,
        std::plus<>(),
        [](const auto& a, const auto& b) {
            double diff = static_cast<double>(a) - static_cast<double>(b);
            return diff * diff;
        }
    );

    return std::sqrt(sum_sq / y_true.size());
}

int main() {
    {
        std::vector<int> v = {1, 2, 3, 2, 4};
        rng::replace(v, 2, 99);
        print_vector(v, "replace 2 -> 99");
    }

    std::cout << "-------------------------\n";

    {
        std::vector<int> v(5);
        rng::fill(v, 7);
        print_vector(v, "fill with 7");
    }

    std::cout << "-------------------------\n";

    {
        std::vector<int> v = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5};
        auto res = rng::unique(v);
        v.erase(res.begin(), v.end());
        print_vector(v, "unique consecutive duplicates");
    }

    std::cout << "-------------------------\n";

    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        rng::rotate(v, v.begin() + 2);
        print_vector(v, "rotate at position 2");
    }

    std::cout << "-------------------------\n";

    {
        std::vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80};
        std::vector<int> out;
        std::mt19937 gen(42);

        rng::sample(v, std::back_inserter(out), 3, gen);

        print_vector(v, "original");
        print_vector(out, "sample 3 elements");
    }

    std::cout << "-------------------------\n";

    {
        std::vector<int> v = {1, 2, 3, 4, 5, 6};

        auto result = transform_if(
            v,
            [](int x) { return x % 2 == 0; },
            [](int x) { return x * x; }
        );

        print_vector(v, "input");
        print_vector(result, "transform_if (even -> square)");
    }

    std::cout << "-------------------------\n";

    {
        std::vector<double> y_true = {3.0, -0.5, 2.0, 7.0};
        std::vector<double> y_pred = {2.5, 0.0, 2.0, 8.0};

        std::cout << "MAE  = " << mae(y_true, y_pred) << '\n';
        std::cout << "RMSE = " << rmse(y_true, y_pred) << '\n';
    }

    return 0;
}