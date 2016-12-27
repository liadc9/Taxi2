//
// Created by gal on 30/11/16.
//

#ifndef TAXI_DRIVER_H
#define TAXI_DRIVER_H


#include "ITaxiCab.h"
#include "Passenger.h"
class Passenger;
enum Status{Single, Marride, Divorced, Widowed};

class Driver {
private:
    int id;
    int age;
    int experience;
    double satisfaction;
    ITaxiCab* taxiCabInfo;
    Status status;
    Passenger* customer;
    bool onTrip;

public:
    Driver(int id, int age, int expirience, double satisfaction, ITaxiCab* taxiCabInfo, Status status,
           Passenger* customer, bool onTrip);

    bool isOnTrip();

    void setOnTrip(bool onTrip);

    int getId();

    int getAge();

    int getExperience();

    double getSatisfaction();

    ITaxiCab* getTaxiCabInfo();

    Status getStatus();

    void setId(int id);

    void setAge(int age);

    void setExperience(int expirience);

    void setSatisfaction(double satisfaction);

    void setTaxiCabInfo(ITaxiCab *taxiCabInfo);

    void setStatus(Status status);

    void setCustomer(Passenger *customer);

    Passenger* getCustomer();
};


#endif //TAXI_DRIVER_H
