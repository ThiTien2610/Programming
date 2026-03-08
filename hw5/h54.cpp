// Implement classes to represent triangles, squares, and circles. 
// Implement the necessary constructors and member functions to calculate perimeter and area

#include<iostream>
#include<cmath>

class Triangle
{
    private:
        double a,b,c;
    public:
        Triangle (double x, double y, double z)
        {
            a=x;b=y;c=z;
        }
        
        double perimeter() const
        {
            return a+b+c;
        }

        double area() const
        {
            double p= perimeter()/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));

        }
};
class Square
{
    private:
        double side;
    public:
        Square(double x)
        {
            side=x;
        }
        double perimeter() const
        {
            return side*4;
        }
        double area() const
        {
            return side*side;
        }
};
class Circle
{
    private:
        double radius;
    public:
        Circle(double r)
        {
            radius=r;
        }
        double perimeter()const
        {
            return 2* M_PI * radius;
        }
        double area()const
        {
            return M_PI * radius*radius;
        }
};
int main()
{
    double a,b,c,r,x;
    std::cout<<"Enter x side of Square:"<<'\n';
    std::cin>>x;
    Square sq_1(x);
    std::cout<<"Square perimeter: "<< sq_1.perimeter()<<'\n';
    std::cout<<"Square area: "<< sq_1.area()<<'\n';

    std::cout<<"Enter r radius of Circle:"<<'\n';
    std::cin>>r;
    Circle ci_1(r);
    std::cout<<"Circle perimeter: "<< ci_1.perimeter()<<'\n';
    std::cout<<"Circle area: "<< ci_1.area()<<'\n';

    std::cout<<"Enter a,b,c side of Triangle:"<<'\n';
    std::cin>>a>>b>>c;
    Triangle tr_1(a,b,c);
    std::cout<<"Triangle perimeter: "<< tr_1.perimeter()<<'\n';
    std::cout<<"Triangle area: "<< tr_1.area()<<'\n';

    return 0;

}
