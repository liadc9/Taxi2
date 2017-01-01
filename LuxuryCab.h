//
// Created by gal on 30/11/16.
//

#ifndef TAXI_LUXURYCAB_H
#define TAXI_LUXURYCAB_H


#include "ITaxiCab.h"
#include "Grid.h"

class LuxuryCab: public ITaxiCab {

public:
    LuxuryCab(int Cab_ID, int distance_made, Color color, Model model, int coeficient,
              int speed, State* location, bool hasDriver, vector<Point> route):ITaxiCab(Cab_ID,distance_made,color,
                                                    model,coeficient,speed,location, hasDriver, route){} ;

    State* move(State* start ,State* rideStart, Grid* grid);

    };

#endif //TAXI_LUXURYCAB_H
