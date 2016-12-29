//
// Created by gal on 30/11/16.
//

#ifndef FAST_TEXI_PASSENGER_H
#define FAST_TEXI_PASSENGER_H

#include "TaxiCenter.h"
#include "State.h"
class TaxiCenter;

class Passenger {
private:
    State* start_point;
    State* end_point;
public:
    Passenger(State* start_point, State* end_point);

    Passenger();

    State* getStart_point();

    void setStart_point(State* start_point);

    State* getEnd_point();

    void setEnd_point(State* end_point);

    void CatchRide(TaxiCenter* taxiCenter);

    void letSetisfaction(TaxiCenter* taxiCenter);

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & start_point;
        ar & end_point;

    }
};

#endif //TAXI_PASSENGER_H
