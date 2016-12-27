/**
 * This class holds all info regarding the trip
 */

#include <iostream>
#include "State.h"
#include "Grid.h"
#include "Trip.h"

/**
 * trip constructor holding all trip info
 * @param id - trip id
 * @param start1 - start of trip
 * @param stop1 - end of trip
 * @param grid1 - grid recevied
 * @param passengers - passengers in trip
 * @param tariff - cost of trip
 */
Trip::Trip(int id, State* start1, State* stop1, Grid* grid1, int passengers, double tariff){
    this->ride_id = id;
    this->start = start1;
    this->stop = stop1;
    this->grid = grid1;
    this->numOfPassengers = passengers;
    this->tariff = tariff;
}
/**
 * contructor of trip
 * @param start1 - start of trip
 * @param stop1 - end of trip
 * @param grid1 - grid recevied
 */
Trip::Trip(State* start1, State* stop1, Grid* grid1){
    this->start = start1;
    this->stop = stop1;
    this->grid = grid1;
}
/**
 * getter for start of trip
 * @return start of trip
 */
State* Trip:: getStart()
{
    return start;
}
/**
 * getter for end of trip
 * @return end of trip
 */
State* Trip:: getdest(){
    return stop;
}
/**
 * getter for grid
 * @return the grid
 */
Grid* Trip:: getGrid(){
    return grid;
}
/**
 * getter for ride id
 * @return id
 */
int Trip::getRide_id(){
    return ride_id;
}
/**
 * getter for num of passengers
 * @return numOfPassengers
 */
int Trip::getNumOfPassengers() {
    return numOfPassengers;
}
/**
 * getter for tariff
 * @return tariff
 */
double Trip::getTariff(){
    return tariff;
}
/**
 * getter for distance made
 * @return distance made
 */
int Trip::getMeter_passed(){
    return meter_passed;
}
/**
 * seeter for ride id
 * @param ride_id
 */
void Trip::setRide_id(int ride_id) {
    Trip::ride_id = ride_id;
}
/**
 * setter for num of passengers
 * @param numOfPassengers
 */
void Trip::setNumOfPassengers(int numOfPassengers) {
    Trip::numOfPassengers = numOfPassengers;
}
/**
 * set for tariff
 * @param tariff
 */
void Trip::setTariff(int tariff) {
    Trip::tariff = tariff;
}
/**
 * setter for distance made
 * @param meter_passed
 */
void Trip::setMeter_passed(int meter_passed) {
    Trip::meter_passed = meter_passed;
}
/**
 * setter for start position
 * @param start
 */
void Trip::setStart(State *start) {
    Trip::start = start;
}
/**
 * sette for stop position
 * @param stop
 */
void Trip::setStop(State *stop) {
    Trip::stop = stop;
}
/**
 * setter for a grid
 * @param grid
 */
void Trip::setGrid(Grid *grid) {
    Trip::grid = grid;
}
