#pragma once
#include <iostream>
#include <ostream>

namespace geometry2d
{

    class Shape2D
    {
    protected:
        int x;

        int y;

    public:
        virtual ~Shape2D()
        {
            std::cout << "~Shape2D()" << std::endl;
        }

        Shape2D() = default;

        [[nodiscard]] Shape2D(const int& x, const int& y)
            : x(x),
              y(y)
        {}

        [[nodiscard]] int get_x() const
        {
            return x;
        }

        void set_x(const int x)
        {
            this->x = x;
        }

        [[nodiscard]] int get_y() const
        {
            return y;
        }

        void set_y(const int y)
        {
            this->y = y;
        }

        void move(const int& x, const int& y)
        {
            this->x = x;
            this->y = y;
        }

        [[nodiscard]] virtual double get_perimeter() const = 0;

        [[nodiscard]] virtual double get_area() const = 0;

    };
}
