 // An algorithm for calculating the intersection area of ​​two rectangles whose sides are parallel to the coordinate axes. 
 // Use structures

 #include<iostream>
 #include<algorithm>

 struct Rectangle
 {
    double x,y;
    double w,h;
 };
 bool is_intersect (Rectangle a, Rectangle b)
 {
    return (a.x+a.w>=b.x)&&
        (b.x+b.w>=a.x)&&
        (a.y+a.h>=b.y)&&
        (b.y+b.h>=a.y);
 }
 double Area_intersection( Rectangle a, Rectangle b)
 {
    if (!is_intersect(a,b))
        return 0.0;

    double x_left= std::max(a.x, b.x);
    double y_bottom=std::max(a.y,b.y);
    double x_right = std::min(a.x+a.w, b.x+b.w);
    double y_top=std::min(a.y+ a.h,b.y+b.h);

    double width=x_right-x_left;
    double height= y_top-y_bottom;

    return width* height;
}
 int main()
 {
    Rectangle r1, r2;
    std::cout<< "Enter x y w h for r1:";
    std::cin >>r1.x>>r1.y>>r1.w>>r1.h;
    std::cout<< "Enter x y w h for r2:";
    std::cin >>r2.x>>r2.y>>r2.w>>r2.h;

    if (is_intersect(r1,r2))
    {
        std::cout<< "2 Rectangles intersect! \n";
        std::cout<< "Area interstion is:"<< Area_intersection(r1,r2)<<'\n';
    }
    else
    {
        std::cout<< " 2 Rectangles do not intersect!\n";
    }
    return 0;
 }