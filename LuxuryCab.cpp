/**
 * this class includes all methds specifically for luxury cab
 */

#include "LuxuryCab.h"
#include "Grid.h"
#include "Trip.h"
#include "BFS.h"
/**
 * this mehod is used for creating the move method for a lexury ab on the grid
 * @param start - start position of the cab
 * @param rideStart - end position (pos of customer for start, or fin pos for ride)
 * @param grid - given grid.
 */
void LuxuryCab::findClosestDriver(State* start,State* rideStart, Grid* grid) {
    // new trip
    Trip* trip = new Trip(start,rideStart,grid);
    // use BFS algorithm
    BFS* bfs = new BFS(trip);
    // check size of vector of BFS route
    unsigned int sizeOfSteps = bfs->AlgoRun().size();
    // get value of next position
    int x = bfs->getBFSreturn().at(2).getX();
    int y = bfs->getBFSreturn().at(2).getY();
    // change the position stored in the cab.
    State* cabNewState = grid->getState(x,y);
    setLocation(cabNewState);
}

bool LuxuryCab::move(ITaxiCab cab) {

    //get current location
    Point current(cab.getLocation()->getState().getX(),location->getState().getY());
    // find where we are in the route by comparing all elements to current location
    for(int i = 0; i < route.size(); i++) {
        if (cab.getRoute().at(i).getX() == current.getX() && route.at(i).getY() == current.getY()) {

            //check that next move is in scope before we make it
            if(i+2 <= cab.getRoute().size()){
                // next position point for standard taxi
                Point newPoint(cab.getRoute().at(i + 2).getX(), cab.getRoute().at(i + 2).getY());
                //create new state for driver location
                State *newPos = new State(newPoint, NULL, false);
                cab.setLocation(newPos);
                // have we reached end of route?
                if(i+3 < cab.getRoute().size()){
                    return false;
                } else {
                    return true;
                }
                // we must only move one more step before we reach the end of route
            } else if(i+2 <= cab.getRoute().size()){
                // next position point for standard taxi
                Point newPoint(cab.getRoute().at(i + 1).getX(), cab.getRoute().at(i + 1).getY());
                //create new state for driver location
                State *newPos = new State(newPoint, NULL, false);
                cab.setLocation(newPos);
                return true;
            }
        }
    }
}
