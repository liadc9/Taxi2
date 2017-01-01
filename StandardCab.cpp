/**
 * this class includes all methds specifically for standard cab
 */

#include "StandardCab.h"
#include "Trip.h"
#include "BFS.h"
/**
 * this mehod is used for creating the move method for a standard ab on the grid
 * @param start - start position of the cab
 * @param rideStart - end position (pos of customer for start, or fin pos for ride)
 * @param grid - given grid.
 */
void StandardCab::findClosestDriver(State* start,State* rideStart, Grid* grid) {
    // new trip
    Trip* trip = new Trip(start,rideStart,grid);
    // use BFS algorithm
    BFS* bfs = new BFS(trip);
    // check size of vector of BFS route
    unsigned int sizeOfSteps = bfs->AlgoRun().size();
    // get value of final position
    int x = bfs->getBFSreturn().at(1).getX();
    int y = bfs->getBFSreturn().at(1).getY();
    // change the position stored in the cab.
    State* cabNewState = grid->getState(x,y);
    setLocation(cabNewState);
}

bool StandardCab::move(ITaxiCab cab) {

    //get current location
    Point current(cab.getLocation()->getState().getX(),cab.getLocation()->getState().getY());
    // find where we are in the route by comparing all elements to current location
    for(int i = 0; i < cab.getRoute().size(); i++) {
        if (cab.getRoute().at(i).getX() == current.getX() && cab.getRoute().at(i).getY() == current.getY()) {

            //check that next move is in scope before we make it
            if(i+1 <= cab.getRoute().size()){
                // next position point for standard taxi
                Point newPoint(cab.getRoute().at(i + 1).getX(), cab.getRoute().at(i + 1).getY());
                //create new state for driver location
                State *newPos = new State(newPoint, NULL, false);
                cab.setLocation(newPos);
                //check if we can continue movement for next iteration
                if(i+2 < route.size()){
                    return false;
                } else {
                    return true;
                }
            } else {
                return true;
            }

        }
    }
}