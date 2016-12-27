
#ifndef FAST_TEXI_TRIP_H
#define FAST_TEXI_TRIP_H
#include<iostream>
#include <vector>
#include "ISearchable.h"
#include "Grid.h"


using namespace std;

class Trip : public ISearchable
{
private:
    int ride_id;
    int numOfPassengers;
    double tariff;
    int meter_passed;
    State* start;
    State* stop;
    Grid* grid;
public:

    Trip(int id, State* start, State* stop ,Grid* grid, int passengers, double tariff);
    Trip(State* start1, State* stop1, Grid* grid1);
    virtual State* getStart();
    virtual State* getdest();
    virtual Grid* getGrid();

    int getRide_id();

    int getNumOfPassengers();

    double getTariff();

    int getMeter_passed();

    void setRide_id(int ride_id);

    void setNumOfPassengers(int numOfPassengers);

    void setTariff(int tariff);

    void setMeter_passed(int meter_passed);

    void setStart(State *start);

    void setStop(State *stop);

    void setGrid(Grid *grid);
};


#endif //TAXI_TRIP_H
