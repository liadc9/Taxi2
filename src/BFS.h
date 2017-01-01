#include "State.h"
#include "ISearchable.h"
#include <iostream>
#include<queue>

#ifndef FAST_TEXI_BFS_H
#define FAST_TEXI_BFS_H

using namespace std;

class Isearchable;
class Trip;
class State;

class BFS {
public:
    BFS(ISearchable* searchable);
    vector<Point> AlgoRun();
    void VectorReturn(State* finish);
    vector<Point> getBFSreturn();
private:
    int wid;
    int hig;
    int xCord;
    int yCord;
    ISearchable* mysearch;
    queue<State*> *nodeQueue;
    queue<State*> *path;
    State *finish;
    vector<Point> BFSreturn;

};


#endif //TAXI_BFS_H
