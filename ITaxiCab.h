//
// Created by gal on 30/11/16.
//
#ifndef TAXI_TAXICAB_H
#define TAXI_TAXICAB_H

#include <iostream>
#include <cstring>
#include "State.h"
#include "Grid.h"

enum Color {RED = 0,BLUE = 1,GREEN = 2,PINK = 3,WHITE = 4};
enum Model{HONDA,SUBARU,TESLA,FIAT};

using namespace std;

class ITaxiCab {

protected:
    int coeficient;
    int Cab_ID;
    int distance_made;
    Color color;
    Model model;
    int speed;
    State* location;
    bool hasDriver;

public:
    ITaxiCab(int Cab_ID, int distance_made, Color color, Model model, int coeficient,
              int speed, State* location, bool hasDriver);
    ~ITaxiCab(){}

    int getCab_ID();

    int getCoeficient();

    int getDistance_made();

    Color getColor();

    Model getModel();

    int getSpeed();

    State* getLocation();

    bool isHasDriver();

    void setHasDriver(bool hasDriver);


    void setCab_ID(int Cab_ID);

    void setDistance_made(int distance_made);

    void setColor(Color color);

    void setCoeficient(int coeficient);

    void setModel(Model model);

    void setSpeed(int speed);

    void setLocation(State* location);

    virtual void move(State* start ,State* rideStart, Grid* grid) = 0;
};


#endif //TAXI_TAXICAB_H
