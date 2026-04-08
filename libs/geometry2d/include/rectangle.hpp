#pragma once

#include "shape2d.hpp"

namespace geometry2d
{

    class Rectangle final: public Shape2D
    {
        int width;

        int height;

    public:
        Rectangle() = default;

        [[nodiscard]] Rectangle(const int& x, const int& y, const int& width, const int& height)
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
            return width * height;
        }


        [[nodiscard]] double get_perimeter() const override
        {
            return 2 * (width + height);
        }
    };
}
