#pragma once

#include <string>
#include <utility>

/*
 A class the represents points in 2-diminesional space.
 */
class Point2D {
public:

    /*
     The x-coordinate of the point.
     */
    double x;

    /*
     The y-coordinate of the point.
     */
    double y;

    /*
     Creates a new Point2D whose x- and y-coordinates are both zero.
     */
    Point2D();

    /*
     Creates a new Point2D with the specified x- and y-coordinates.
     */
    Point2D(double x, double y);

    /*
     Computes the distance from this point to the specified one.
     Uses <cmath>'s hypot function to reduce the chance of overflow.
     */
    double distanceTo(Point2D Q) {
        double distance = hypot(this->x - Q.x, this->y - Q.y);
        return distance;

    }

    /*
     Computes the distance from this point to the origin (0,0).
     */
    double norm(Point2D Q) {
        Point2D();
        double dis = hypot(Q.x - 0, Q.y - 0);
        return dis;
    }

    /*
     Swaps the x- and y-coordinates of this point.
     */
    void swap() {
        double w = this->x;
        double z = this->y;
        this->x == z;
        this->y == w;
    }

    /*
     Overload the += operator.
     REFER SNAPCHAT PICTURE
     */
    Point2D& operator+=(const Point2D& rhs);

    /*
     Overload the + operator. Note: this function is not a member function of
     class Point2D. Rather, it is a "friend" function, which means that it is a
     non-member function that nevertheless has access to private and protected
     data members of Point2D.
     */
    friend Point2D operator+(const Point2D& lhs, const Point2D& rhs);

    /*
     Returns true if and only if the specified point as the same x- and y 
     components as this one.
     */
    bool operator!=(const Point2D& another);

    /*
     Returns a string representation of this point.
     */
    std::string toString();
        
};
