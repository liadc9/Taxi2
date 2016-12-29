#include "Point.h"
#include <iostream>
#include "ISearchable.h"
#include "Map.h"

#ifndef FAST_TEXI_GRID_H
#define FAST_TEXI_GRID_H

class Grid: public Map{
public:
    Grid();
    Grid(int width, int height);
    int getHeight();
    int getWidth();
    vector<State*> get_neighbor(State* startS, Grid* ourGrid);
    State* getState(int x, int y);
    void setWasHere(int x, int y);
    vector<int> getSizes();
    void afterAlgoRun();
    virtual ~Grid();
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & height;
        ar & width;
        ar &  myGrid;
    }

private:
    int width;
    int height;
    State** myGrid;

};


#endif //TAXI_GRID_H
