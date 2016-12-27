/**
 * The following class hold all operation of the Taxi center
 */
//gal is the king
//this is right
#include "TaxiCenter.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "Waze.h"
/**
 * constrcutor for taxi center
 */
TaxiCenter::TaxiCenter(){
    vector<Trip*> trips;
    vector<StandardCab*> taxis;
    vector<LuxuryCab*> luxTaxis;
    vector<Driver*> drivers;
}
/**
 * getter for the trips vector held by taxi center
 * @return vector of trips
 */
vector<Trip*> TaxiCenter::getTrips() {
    return trips;
}

/**
 * getter for the taxis vector held by taxi center
 * @return vector of taxis
 */
vector<StandardCab*> TaxiCenter::getTaxis() {
    return taxis;
}
/**
 * getter for the lux taxis vector held by taxi center
 * @return vector of lux taxis
 */
vector<LuxuryCab*> TaxiCenter::getLuxTaxis() {
    return luxTaxis;
}
/**
 * getter for the drivers vector held by taxi center
 * @return vector of taxis
 */
vector<Driver*> TaxiCenter::getDrivers() {
    return drivers;
}
/**
 * this method adds a taxi to the taxi vector
 * @param taxiCab
 */
void TaxiCenter::AddTaxiCab(StandardCab* taxiCab) {
        taxis.push_back(taxiCab);
}

/**
 * this method adds a lux taxi to the taxi vector
 * @param taxiCab
 */
void TaxiCenter::AddTaxiLux(LuxuryCab* taxiCab) {
        luxTaxis.push_back(taxiCab);
}
/**
 * this method adds a trip to the trip vector
 * @param trip
 */
void TaxiCenter::AddTrip(Trip* trip) {
    trips.push_back(trip);
}
/**
 * this method adds a driver to the driver vector
 * @param driver
 */
void TaxiCenter::AddDriver(Driver* driver) {
    drivers.push_back(driver);
}
/**
 * this method is used to find the closest driver and assign it to a customer using waze class
 * then it moves the closest cab to pick up a customer and take it to destination.
 * @param trip
 */
void TaxiCenter::tripCreator(Trip* trip) {
    Waze* waze = new Waze();
    Driver* driver;
    State* start = trip->getStart();
    State* end = trip->getdest();
    Grid* grid = trip->getGrid();
    // finds closest driver to customer
    driver = waze->findClosest(drivers,start,grid);
    State* driverState = driver->getTaxiCabInfo()->getLocation();
    if((driverState->getState().getX() != start->getState().getX()) &&
            (driverState->getState().getY() != start->getState().getY())){
        driver->getTaxiCabInfo()->move(driverState,start,grid);
    }
    // move cab to end point
    driver->getTaxiCabInfo()->move(start,end,grid);
    delete waze;
}
/**
 * answer customer call - not implemented yt
 * @param customer - calling customer
 */
void TaxiCenter::answerCall(Passenger* customer){

}
/**
 * this method is used to get location of a cab
 * @param cab - given cab
 * @return cab position state
 */
State* TaxiCenter::CabLocation(StandardCab* cab){
    for (int i =0; i < taxis.size(); i++){
        if(taxis.at(i) == cab){
            return taxis.at(i)->getLocation();
        }
    }
    return NULL;
}
/**
 * this method is used to get location of a luxury cab
 * @param cab - given luxury cab
 * @return luxury cab position state
 */
State* TaxiCenter::LuxCabLocation(LuxuryCab* cab){
    for (int i =0; i < luxTaxis.size(); i++){
        if(luxTaxis.at(i) == cab){
            return luxTaxis.at(i)->getLocation();
        }
    }
    return NULL;
}

