#include <iostream>
#include "Point.h"
#ifndef FAST_TAXI_STATE_H
#define FAST_TAXI_STATE_H

using namespace std;


class State {
public:
    State();
    //constructor
    State(Point state, State* comeFrom, bool wasHere);

    bool Comparison(State other);

    Point getState();

    State* getComeFrom();

    bool getWasHere();

    int getIsObstacle();

    void setState(Point s);

    void setComeFrom(State* s);

    void setWasHere(bool s);

    void setIsObstacle(int x);

private:
    int isObstacle;
    Point state ;
    State* comeFrom;
    bool wasHere;

};


#endif //TAXI_STATE_H
