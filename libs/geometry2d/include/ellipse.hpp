#pragma once

#include <cmath>
#include "shape2d.hpp"

namespace geometry2d
{
    class Ellipse final: public Shape2D
    {
        int width;

        int height;

    public:
        Ellipse()
            :Shape2D(),
            width(0),
            height(0)
        {}

        [[nodiscard]] Ellipse(const int& x, const int& y, const int& width, const int& height)
            : Shape2D(x, y),
              width(width),
              height(height)
        {}

        [[nodiscard]] int get_width() const
        {
            return width;
        }

        void set_width(const int width)
        {
            this->width = width;
        }

        [[nodiscard]] int get_height() const
        {
            return height;
        }

        void set_height(const int height)
        {
            this->height = height;
        }

        [[nodiscard]] double get_area() const override
        {
            return M_PI * width * height;
        }


        [[nodiscard]] double get_perimeter() const override
        {
            return M_PI * std::sqrt(2 *(width*width + height*height));
        }
    };
}
