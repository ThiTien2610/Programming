#pragma once
#include <iostream>

namespace hw12
{
class Rational
{
public:
    Rational(int num =0, int den =1);

    explicit operator double() const
    {
        return 1.0 * m_num / m_den;
    }

    Rational& operator+=(Rational const& other);
    Rational& operator-=(Rational const& other)
    {
        return *this += Rational(-other.m_num, other.m_den);
    }
    Rational& operator*=(Rational const& other); 
    Rational& operator/=(Rational const& other)
    {
        return *this *= Rational(other.m_den, other.m_num);
    }

    Rational operator++(int)
    {
        Rational x = *this;
        *this += 1;
        return x;
    }

    Rational operator--(int)
    {
        Rational x = *this;
        *this -= 1;
        return x;
    }

    Rational& operator++()
    {
        *this += 1;
        return *this;
    }

    Rational& operator--()
    {
        *this -= 1;
        return *this;
    }

    friend Rational operator+(Rational lhs, Rational const& rhs) { return lhs += rhs; }
    friend Rational operator-(Rational lhs, Rational const& rhs) { return lhs -= rhs; }
    friend Rational operator*(Rational lhs, Rational const& rhs) { return lhs *= rhs; }
    friend Rational operator/(Rational lhs, Rational const& rhs) { return lhs /= rhs; }

    friend bool operator<(Rational const& lhs, Rational const& rhs)
    {
        return lhs.m_num * rhs.m_den < rhs.m_num * lhs.m_den;
    }

    friend bool operator>(Rational const& lhs, Rational const& rhs)  { return (rhs < lhs); }
    friend bool operator<=(Rational const& lhs, Rational const& rhs) { return !(lhs > rhs); }
    friend bool operator>=(Rational const& lhs, Rational const& rhs) { return !(lhs < rhs); }
    friend bool operator==(Rational const& lhs, Rational const& rhs)
    {
        return !(lhs < rhs) && !(rhs < lhs);
    }
    friend bool operator!=(Rational const& lhs, Rational const& rhs)
    {
        return !(lhs == rhs);
    }

    friend std::istream& operator>>(std::istream& stream, Rational& rational);
    friend std::ostream& operator<<(std::ostream& stream, Rational const& rational);

private:
    void reduce();
    int m_num = 0;
    int m_den = 1;
};
}