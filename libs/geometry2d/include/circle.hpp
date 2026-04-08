#pragma once

#include <cmath>
#include <iostream>
#include <ostream>

#include "shape2d.hpp"

namespace geometry2d
{
    class Circle final: public Shape2D
    {
        int radius;

    public:
        Circle() = default;

        [[nodiscard]] Circle(const int& x, const int& y, const int& radius)
            : Shape2D(x, y),
              radius(radius)
        {
        }

        ~Circle() override
        {
            std::cout<<"~Circle()"<<std::endl;
        }

        [[nodiscard]] int get_radius() const
        {
            return radius;
        }

        void set_radius(const int radius)
        {
            this->radius = radius;
        }

        [[nodiscard]] double get_area() const override
        {
            return M_PI * radius * radius;
        }


        [[nodiscard]] double get_perimeter() const override
        {
            return 2* M_PI * radius;
        }
    };
}
