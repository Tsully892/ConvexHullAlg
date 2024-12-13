#include <cmath>
#include <sstream>

#include "Point2D.hpp"

Point2D::Point2D() {
    this->x = 0;
    this->y = 0;
}

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

Point2D& Point2D::operator+=(const Point2D& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Point2D operator+(const Point2D& lhs, const Point2D& rhs) {
    Point2D result;
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    return result;
}

bool Point2D::operator!=(const Point2D& another) {
    return (this->x != another.x || this->y != another.y);
}


std::string Point2D::toString() {
    std::ostringstream sout;
    sout << "Point2D: (" << this->x << ", " << this->y << ")" << std::endl;
    return sout.str();
}
