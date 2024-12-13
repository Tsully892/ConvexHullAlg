#pragma once

#include <utility>
#include <list>
#include <string>
#include <sstream>
#include <iostream>

#include "Point2D.hpp"
#include "TroysList.hpp"

/*
 A class the represents the convex hull of a finite set of points in the plane.
 */
class ConvexHull {

protected:

    /*
     Each pair of points in this list represents one edge of the convex hull.
     */
    List<std::pair<Point2D, Point2D>*>* lst;

    //List of points to begain work
    List<Point2D>* Points;

    //Allows for a golbal edge to be used -- MAY NOT BE NECCESSARY
    std::pair<Point2D, Point2D>* Edge;


public:
    //Defult constructer doesnt do anything, 
    //but allows for program to run w/o complete constructor active
    ConvexHull() {
        List<std::pair<Point2D, Point2D>*>* lst = new List<std::pair<Point2D, Point2D>*>();
    }

    /*
     Creates the convex hull of the given set of points.
     */
    ConvexHull(List<Point2D>* points) {
        List<std::pair<Point2D, Point2D>*>* lst = new List<std::pair<Point2D, Point2D>*>();
        // store the points.
        this->Points = points;

        // create a list of pairs of Point2D in the following order
        // (0,1),(1,2),...(n-2,n-1), (0,2), (1,3), ... (n-3,n-1), (0,3)....,(0,n-1)
        // generate each pair, check it, close it and check validity. If valid, stop.
        // otherwise go to the next edge.

        int size = points->size();
        int skip = 1;
        int n = 0;

        for (skip; skip < size; skip++) {
            int pairs = size - skip;

            for (int i = 0; i < pairs; i++) {
                Point2D pi = points->get(i);
                Point2D pj = points->get(i + skip);

                std::pair<Point2D, Point2D>* pairIJ = new std::pair<Point2D, Point2D>(pi, pj);
                bool check = checkEdge(pairIJ, this->Points);

                if (check == true) {
                    lst->insert(pairIJ, n);
                    n++;
                }
            }
        }


        this->lst=lst;
        std::cout << this->lst->toString() << std::endl;

        for (int m = 0; m < this->lst->size(); m++) {
            std::pair<Point2D, Point2D> pair = *this->lst->get(m);
            Point2D x = pair.first;
            Point2D y = pair.second;
            std::cout << "Edges: " << x.toString() << y.toString() << std::endl;
        }

    }


    //Checks each edge to make sure it is a part of our convexhull
    //if true add into lst
    //EQUATION ((B.x - A.x) * (C.y - A.y)) - ((B.y - A.y) * (C.x - A.x))
    bool checkEdge(std::pair<Point2D, Point2D>* edge, List<Point2D>* points){
        List <double>* checkVals = new List<double>;
        int lt = 0, gt = 0, z = 0;
        int a = 0;
        bool check = 0;
        int size = points->size();
        Point2D A = edge->first;
        Point2D B = edge->second;
        double Ax = A.x;
        double Ay = A.y;
        double Bx = B.x;
        double By = B.y;
        for (int i = 0; i < size; i++) {
            Point2D C = points->get(i);
            double Cx = C.x;
            double Cy = C.y;
            bool checkA = C != A;
            bool checkB = C != B;
            std::cout << checkA << " ";
            std::cout << checkB << std::endl;
            if (checkA == true && checkB == true) {
                double sides = ((B.x - A.x) * (C.y - A.y)) - ((B.y - A.y) * (C.x - A.x));
                std::cout << sides << std::endl;
                checkVals->insert(sides, a);
                a++;
            }
            
        }
        int data = this->Points->size();
        List<double>* lessThan = new List<double>;
        List<double>* greaterThan = new List<double>;
        List<double>* equal = new List<double>;

        if (data >= 4) {
            int checkSize = checkVals->size();
            for (int d = 0; d < checkSize; d++) {
                double c1 = checkVals->get(d);
                if (c1 < 0) {
                    lessThan->insert(c1, lt);
                    lt++;
                }
                else if (c1 > 0) {
                    greaterThan->insert(c1, gt);
                    gt++;
                }
                else if (c1 == 0) {
                    equal->insert(c1, z);
                    z++;
                }
            }
            int lts = lessThan->size();
            int gts = greaterThan->size();
            int zs = equal->size();
            int wanted = this->Points->size() - 2;
            if (lts == wanted) {
                check = true;
            }
            else if (gts == wanted) {
                check = true;
            }
            else if (zs == wanted) {
                check = true;
            }
            else {
                check = false;
            }
        }
        else {
            check = true;
        }


        std::cout << checkVals->toString() << std::endl;

        for (int m = 0; m < checkVals->size(); m++) {
            double val = checkVals->get(m);
            std::cout << "CheckVals: " << val << std::endl;
        }
        return check;
    }

    ////Attempts to close the CH with the inital point to check if we need to end the program
    //bool tryZero(std::pair<Point2D, Point2D>* edge, List<Point2D>* points) {
    //    Point2D initalPoint = points->get(0);
    //    Point2D A = edge->first;
    //    int size = lst->size();

    //    std::pair<Point2D, Point2D>* close = new std::pair<Point2D, Point2D>(A, initalPoint);
    //    bool check = checkEdge(close, Points);
    //    if (check == false) {
    //        return false;
    //    }
    //    bool empty = lst->isEmpty();

    //    for (int i = 0; i <= size; i++) {
    //        if (check == true && empty == true) {
    //            lst->insert(close, 0);
    //        }
    //        if (check == true && i == size) {
    //            i++;
    //            lst->insert(close, i);
    //        }
    //    }
    //    return true;
    //}


    /*
     Returns the number of edges in the convex hull.
     */
    int getNumEdges() {
        return lst->size();
    }

    /*
     Returns the ith edge from this convex hull. Edges are indexed from zero.
     */
    std::pair<Point2D, Point2D>* getEdge(int i) {
        return lst->get(i);
    }

    /*
     Returns a list of all the edges in this convex hull.
     */
    List<std::pair<Point2D, Point2D>*>* getEdges() {
        return lst;
    }

    /*
     Returns a string representation of this convex hull.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "The Convex Hull at: " << this->lst << std::endl;
        sout << "The number of edges in the convex hull is " << this->getNumEdges() << std::endl;

        return sout.str();
    }

};
