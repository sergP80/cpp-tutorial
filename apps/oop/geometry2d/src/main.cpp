#include "app.hpp"

using std::cin;
using std::cout;
using std::endl;
using geometry2d::Shape2D;
using geometry2d::Rectangle;
using geometry2d::Circle;
using geometry2d::Square;

int main()
{

    // {
    //     const Shape2D& s1 = Circle(100, 200, 15);
    //
    //     const Shape2D& s2 = Square(-50, -205, 15);
    //
    //     cout << s1.get_area() << ", " << s1.get_perimeter() << endl;
    //     cout << s2.get_area() << ", " << s2.get_perimeter() << endl;
    // }

    {
        Shape2D* s1 = new Circle(100, 200, 25);

        cout << s1->get_area() << ", " << s1->get_perimeter() << endl;

        Shape2D* s2 = new Square(-10, -215, 30);
        cout << s2->get_area() << ", " << s2->get_perimeter() << endl;

        delete s2;
        delete s1;
    }


    return 0;
}
