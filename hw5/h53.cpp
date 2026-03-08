// An algorithm for calculating the smallest bounding rectangle containing two other rectangles whose sides are parallel to the coordinate axes. 
// Use structures

#include<iostream>
#include<algorithm>

struct Rectangle
{
    double x,y;
    double w,h;
};
Rectangle bounding_rectangle(Rectangle a, Rectangle b )
{
    Rectangle result;
    double x_min=std::min(a.x,b.x);
    double y_min = std::min(a.y, b.y);
    double x_max = std::max(a.x + a.w, b.x + b.w);
    double y_max = std::max(a.y + a.h, b.y + b.h);

    result.x = x_min;
    result.y = y_min;
    result.w = x_max - x_min;
    result.h = y_max - y_min;

    return result;
}
int main()
{
    Rectangle r1, r2;
    std::cout<< "Enter x y w h for r1:";
    std::cin >>r1.x>>r1.y>>r1.w>>r1.h;
    std::cout<< "Enter x y w h for r2:";
    std::cin >>r2.x>>r2.y>>r2.w>>r2.h;

    Rectangle r_bounding = bounding_rectangle(r1,r2);
    std::cout << "Bounding rectangle: \n";
    std::cout << "x = " << r_bounding.x  << ", y = " << r_bounding.y << ", w = " << r_bounding.w << ", h = " << r_bounding.h << "\n";
    return 0;

}