// Implement the IPv4 class to represent IP addresses in the IPv4 standard
// Implement a private standard container std::array of four std::uint8_t elements in the IPv4 class to store IP address components
// Implement overloaded operators for prefix and postfix increment and decrement of IP addresses in the IPv4 class
// Implement overloaded comparison, input, and output operators for IP addresses that are friendly to the IPv4 class
// Use the standard input stream std::stringstream to input IP addresses as four integers from 0 to 255, inclusive, separated by dots.
// Use the standard output stream std::stringstream to output IP addresses in the format used for input.




#include<array>
#include<cstdint>
#include<sstream>
#include<iostream>
#include<string>
class IPv4
{
private:
    std::array<uint8_t,4> data;

public:
    IPv4(): data{0,0,0,0}{}
    IPv4(uint8_t a, uint8_t b, uint8_t c, uint8_t d): data{a,b,c,d} {}
    explicit IPv4(uint32_t value):
        data
        {
            static_cast<uint8_t>((value >> 24)& 0xFF),
            static_cast<uint8_t>((value >> 16)& 0xFF),
            static_cast<uint8_t>((value >> 8)& 0xFF),
            static_cast<uint8_t>(value & 0xFF)
        } {}

        IPv4(const IPv4& other) noexcept= default;
        IPv4&operator=(const IPv4& other) noexcept=default;

        uint32_t to_ulong() const noexcept
        {
            return (static_cast<uint32_t>(data[0])<< 24)|
                   (static_cast<uint32_t>(data[1])<< 16)|
                   (static_cast<uint32_t>(data[2])<< 8)|
                   (static_cast<uint32_t>(data[3]));
        }

        IPv4& operator++()
        {
            *this= IPv4(to_ulong()+1);
            return *this;
        }
        IPv4 operator++(int)
        {
            IPv4 temp(*this);
            ++(*this);
            return temp;
        }

        IPv4& operator--()
        {
            *this= IPv4(to_ulong()-1);
            return *this;
        }
        IPv4 operator--(int)
        {
            IPv4 temp(*this);
            --(*this);
            return temp;
        }

        friend bool operator==(const IPv4& a, const IPv4& b) noexcept {return a.data == b.data;}
        friend bool operator!=(const IPv4& a, const IPv4& b) noexcept {return !(a==b);}
        friend bool operator<(const IPv4& a, const IPv4& b) noexcept {return a.to_ulong()<b.to_ulong();}
        friend bool operator>(const IPv4& a, const IPv4& b) noexcept {return b<a;}
        friend bool operator<=(const IPv4& a, const IPv4& b) noexcept {return !( b<a);}
        friend bool operator>=(const IPv4& a, const IPv4& b) noexcept {return !(a<b);}

        friend std::ostream& operator<<(std::ostream& os, const IPv4& ip)
        {
            os << int (ip.data[0])<< "."<<  int (ip.data[1])<< "."
                << int (ip.data[2])<< "."<<  int (ip.data[3]);
            return os;
        }     
        friend std::istream& operator>>(std::istream& is, IPv4& ip)
        {
            int a0,a1,a2,a3;
            char b1,b2,b3;
            is >>a0>>b1>>a1>>b2>>a2>>b3>>a3;
        

        if(is && b1=='.'&& b2=='.'&& b3=='.'
            && a0>=0&& a0<=255 && a1>=0&& a1<=255 
            && a2>=0&& a2<=255 && a3>=0&& a3<=255)
        {
            ip=IPv4(a0,a1,a2,a3);
        }
        else
        { 
            is.setstate(std::ios_base::failbit);
        }
        return is;
        }
};
int main() 
{
    std::stringstream s1("192.168.1.1");
    IPv4 ip;
    s1>>ip;

    std::cout<< "IP origin: "<<ip<<"\n";

    ++ip;
    std::cout<< "After ++ip: "<<ip<<"\n";

    ip++;
    std::cout<< "After ip++: "<<ip<<"\n";

    --ip;
    std::cout<< "After --ip: "<<ip<<"\n";

    ip--;
    std::cout<< "After ip--: "<<ip<<"\n";

    return 0;
}