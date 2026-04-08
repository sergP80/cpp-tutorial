#pragma once

#include "circle.hpp"
#include "shape2d.hpp"

namespace geometry2d
{

    class Square final: public Shape2D
    {
        int size;
    public:
        Square() = default;

        [[nodiscard]] Square(const int& x, const int& y, const int& size)
            : Shape2D(x, y),
              size(size)
        {}

        ~Square() override
        {
            std::cout<<"~Square()"<<std::endl;
        }

        [[nodiscard]] int get_size() const
        {
            return size;
        }

        void set_size(const int& size)
        {
            this->size = size;
        }

        [[nodiscard]] double get_area() const override
        {
            return size * size;
        }


        [[nodiscard]] double get_perimeter() const override
        {
            return 4* size;
        }
    };

}
