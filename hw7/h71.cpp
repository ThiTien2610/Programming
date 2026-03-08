// Implement the abstract base class Shape to represent the geometric shapes interface. 
//In the class Shape, implement a virtual destructor and public pure virtual member functions perimeter and area to calculate the perimeter and area, respectively.
//Implement the derived class Circle to represent circles, which inherits the interface of the class Shape.
//Implement the derived abstract base class Polygon to represent polygons, which inherits the interface of the class Shape. 
//Implement the derived classes Triangle and Rectangle to represent triangles and rectangles, respectively, which inherit the interface of the class Polygon. 
//Implement a derived class, Square, to represent squares, that inherits the interface of the Rectangle class. Do not create a field in the Square class to store the length of a square's side.
//Implement only a custom constructor in the Square class that calls the constructor of the base class, Rectangle. 
//Use the override specifier when overriding the inherited virtual member functions, perimeter and area, in the Circle, Triangle and Rectangle classes.
// Use the final specifier to prevent inheritance from the Circle and Square classes and to prevent overriding the inherited virtual member functions perimeter and area in classes derived from the Rectangle class.
// Use the standard std::vector container to store instances of the Circle, Triangle and Square classes through pointers to the Shape class. Demonstrate how dynamic polymorphism works

#include<iostream>
#include<cmath>
#include<vector>

class Shape
{
public:
    virtual ~Shape()= default;
    virtual double perimeter()const=0;
    virtual double area()const=0;
    virtual void print()const=0;
};

class Circle final: public Shape
{
public:
Circle(int a):m_r(a){}
void print()const override
{
    std::cout<<"Circle\n";
}
double perimeter()const override final
{
    const double pi = 3.141592653589793;
    return 2*m_r*pi;
}
double area() const override final
{
    const double pi = 3.141592653589793;
    return m_r*m_r*pi;
}
private:
int m_r{};
};

class Polygon: public Shape
{
public:
    virtual ~Polygon()= default;
};

class Triangle: public Polygon
{
public:
Triangle(int a, int b, int c):m_a(a),m_b(b),m_c(c){}
void print()const override
{
    std::cout<<"Triangle\n";
}
double perimeter()const override final
{
    return m_a+m_b+m_c;
}
double area() const override final
{
    double s= perimeter()/2.0;
    return std::sqrt(s*(s-m_a)*(s-m_b)*(s-m_c));
}
private:
int m_a,m_b,m_c{};
};

class Rectangle: public Polygon
{
public:
Rectangle(int a, int b ):m_a(a),m_b(b){}
void print()const override
{
    std::cout<<"Rectangle\n";
}
double perimeter()const override final
{
    return 2*(m_a+m_b);
}
double area() const override final
{
    return m_a*m_b;
}
private:
int m_a,m_b{};
};

class Square final: public Rectangle
{
public:
Square (int a):Rectangle(a,a){}
void print()const override
{
    std::cout<<"Square\n";
}
};

int main()
{
    std::vector< Shape* > shapes;
    shapes.push_back(new Circle(1));
    shapes.push_back(new Triangle(2,3,4));
    shapes.push_back(new Square(5));
    for (auto s:shapes)
    {
        s->print();
        std::cout<<s->perimeter()<<' '<< s->area()<<'\n';
        delete s;
    }
}
