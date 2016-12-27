#include <iostream>
#ifndef FAST_TEXI_POINT_H
#define FAST_TEXI_POINT_H

class Point{
private:
    int xVal;
    int yVal;
public:
    Point();
    Point(int x,int y);
    int getX();
    int getY();
    void setX(int xValue);
    void setY(int yValue);
    friend std::ostream& operator<< (std::ostream &out, const Point &s);
};


#endif //TAXI_POINT_H
