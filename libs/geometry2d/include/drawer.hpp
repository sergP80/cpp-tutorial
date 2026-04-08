
#include "geometry2d.hpp"

namespace geometry2d
{

    class Drawer
    {
        public:
        void draw(const Rectangle& rectangle) const {}
        void draw(const Square& rectangle) const {}
        void draw(const Ellipse& rectangle) const {}
        void draw(const Circle& rectangle) const {}
    };

    class GeometryCompute
    {
    public:
        double areaAll(Rectangle* rectangles, int size) const {}
    };
}