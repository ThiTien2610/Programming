// Solving a quadratic equation with real coefficients a, b, c

#include <iostream>
#include <cmath>

int main()
{
    double a, b, c, delta , x1,x2 ; 
    const double asps= 0.0001;
    std::cout<<"Enter a:";
    std::cin >>a;
    std::cout<<"Enter b:";
    std::cin >>b;
    std::cout<<"Enter c:";
    std::cin >>c;

    delta=(b*b)-4 * a*c;
    if (delta<0)
        std::cout <<"No roots";
    else if (std::abs(delta-0)<asps)
       {
        x1=(-b)/(2*a);
        std::cout <<"Double root x1=x2="<<x1;
       } 
    else
        { 
            x1= ((-b)+sqrt(delta))/(2*a);
            x2= ((-b)-sqrt(delta))/(2*a);
            std::cout <<"Two different roots x1="<<x1 << " x2="<<x2;
        }
    




}