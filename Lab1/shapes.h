#ifndef SHAPES_H
#define SHAPES_H

#include <cmath>

class Shapes {
public:
    double square(double side) {
        return side * side;
    }

    double rectangle(double width, double height) {
        return width * height;
    }

    double parallelogram(double base, double height) {
        return base * height;
    }

    double rhombus(double diag1, double diag2) {
        return (diag1 * diag2) / 2;
    }

    double triangle(double base, double height) {
        return (base * height) / 2;
    }

    double trapezoid(double base1, double base2, double height) {
        return ((base1 + base2) * height) / 2;
    }

    double circle(double radius) {
        return M_PI * radius * radius;
    }

    double sector(double radius, double angle) {
        return (M_PI * radius * radius * angle) / 360;
    }
};

#endif // SHAPES_H
