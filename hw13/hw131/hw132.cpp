#include <iostream>
#include <cmath>
#include <optional>
#include <variant>
#include <utility>

using Roots = std::variant<double, std::pair<double, double>, std::monostate>;
using OptionalRoots = std::optional<Roots>;

static bool is_zero(double x, double eps)
{
    return std::abs(x) < eps;
}

OptionalRoots solve(double a, double b, double c)
{
    const double eps = 0.0001;

    if (is_zero(a, eps))
    {
        if (is_zero(b, eps))
        {
            if (is_zero(c, eps))
                return Roots{std::monostate{}};
            else
                return std::nullopt;
        }

        double x = -c / b;
        return Roots{x};
    }

    double delta = (b*b)-4*a*c;

    if (delta <-eps)
        return std::nullopt;

    if (is_zero(delta, eps))
    {
        double x = (-b)/(2*a);
        return Roots{x};
    }

    double x1 = ((-b) + std::sqrt(delta)) / (2*a);
    double x2 = ((-b) - std::sqrt(delta)) / (2*a);
    return Roots{std::pair<double, double>{x1, x2}};
}

int main()
{
    double a, b, c;
    std::cout << "Enter a:";
    std::cin >> a;
    std::cout << "Enter b:";
    std::cin >> b;
    std::cout << "Enter c:";
    std::cin >> c;

    OptionalRoots result = solve(a, b, c);

    if (!result)
    {
        std::cout << "No roots";
        return 0;
    }

    const Roots& v = *result;

    if (std::holds_alternative<std::monostate>(v))
    {
        std::cout << "Infinite number of roots";
    }
    else if (std::holds_alternative<double>(v))
    {
        double x = std::get<double>(v);
        std::cout << "One root x=" << x;
    }
    else
    {
        auto p = std::get<std::pair<double, double>>(v);
        std::cout << "Two different roots x1=" << p.first << " x2=" << p.second;
    }

    return 0;
}