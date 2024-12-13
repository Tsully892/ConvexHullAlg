#include <iostream>
#include <string>

#include "Point2D.hpp"
#include "TroysList.cpp"
#include "ConvexHull.hpp"

//WORKED
//void Point2DTest00() {
    /*Point2D P(1,2);
    std::cout << "Point P: " << P.toString();
    Point2D Q(3,4);
    std::cout << "Point Q: " << Q.toString();
    Point2D R;
    P += Q;
    std::cout << "Point P after incrementing it by Q: " << P.toString();
    R = P + Q;
    std::cout << "Point R = P + Q: " << R.toString() << std::endl;
}*/

//Builds the data set in Point2D adds it to a Points list, then ships said list to ConvexHull to be worked
void DS1() {
    Point2D P1(3, -3);
    Point2D Q1(-3, 0);
    Point2D R1(3, 0);
    List<Point2D>* points1 = new List<Point2D>();
    points1->insert(P1, 0);
    points1->insert(Q1, 1);
    points1->insert(R1, 2);
    //std::cout << points1->toString() << std::endl;
    ConvexHull::ConvexHull(points1);
}

void DS2() {
    Point2D P2(4, 3);
    Point2D Q2(-3, 4);
    Point2D R2(1, -4);
    Point2D S2(2, 2);
    List<Point2D>* ds2 = new  List<Point2D>();
    ds2->insert(P2, 0);
    ds2->insert(Q2, 1);
    ds2->insert(R2, 2);
    ds2->insert(S2, 3);
    ConvexHull::ConvexHull(ds2);
}

void DS3() {
    Point2D P3(1, 3);
    Point2D Q3(-3, 3);
    Point2D R3(-4, 2);
    Point2D S3(-2, 1);
    Point2D T3(2, 4);
    Point2D U3(4, 3);
    Point2D V3(2, -4);
    Point2D W3(4, -3);
    List<Point2D>* ds3 = new List<Point2D>();
    ds3->insert(P3, 0);
    ds3->insert(Q3, 1);
    ds3->insert(R3, 2);
    ds3->insert(S3, 3);
    ds3->insert(T3, 4);
    ds3->insert(U3, 5);
    ds3->insert(V3, 6);
    ds3->insert(W3, 7);
    ConvexHull::ConvexHull(ds3);
}

int main(int argc, const char* argv[]) {
    std::cout << "Hello, Troy!\n";
    //Point2DTest00(); //WORKED
    //DS1(); //WORKED FULLY OUTPUT RIGHT CONVEXHULL
    //DS2(); //WORKED
    DS3(); //WORKED
    
   
    return 0;
}


//Test Data
//Set 1: [(3,-3), (-3,0), (3,0)] -Triangle 
//Set 2: [(4,3), (-3,4), (1,-4), (2,2)] -Triangle w/random inside point
//Set 3: [(4,4) (-4,-4), (-4,0), (4,0), (-3,3), (3,3), (-1,1) - polygon to have 5 edges w/one random point 

//{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}
//{4,4}, {-4,-4}, {-4,0}, {4,0}, {-3,3}, {3,3}, {-1,1}, {1,2}
//{1,3}, {-3,3}, {-4,2}, {-2,1}, {2,4}, {4,3}, {2,-4}, {4, -3}