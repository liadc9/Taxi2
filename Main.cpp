/**
 * This is the main Class which is used in order to run the BFS algorithm on the grid.
 */
#include "Point.h"
#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"
#include "Trip.h"
#include "Grid.h"
#include "BFS.h"
#include "TaxiCenter.h"
#include <gtest/gtest.h>
#include <boost/any.hpp>
#include "Menu.h"
#include "Main.h"
#include "Udp.h"


using namespace std;

/**
 * This is the main function, it is used to control the flow of the program.
 * it calls the parser to parse arguments, calls the grid class to create a grid.
 * it creates all obstacles for the grid.
 * it then calls the menu to continue the flow.
 * @param argc - args recceived from user
 * @param argv - args received from user
 * @return null;
 */
int main() {
    Socket* socket = new Udp(1,1212);
    socket->initialize();


 //   testing::InitGoogleTest(&argc, argv);
  //  RUN_ALL_TESTS();

    // get grid input from user
    string gridInput;
    getline (cin, gridInput);
    int xSize;
    int ySize;
    int xObstacle;
    int yObstacle;

    // creates new parser object
    Parser parse;

    // create a list of int data
    vector<boost::any> parsedData;

    parsedData = parse.DataSplit(gridInput);

    // creates list for grid coordinates
    vector<Point*> parsedPoints;

    //enters the data for grid size to be understandable.
    xSize = boost::any_cast<int>(parsedData[0]);
    ySize = boost::any_cast<int>(parsedData[1]);

    // grid creation:
    Grid* grid = new Grid(xSize, ySize);

    // get number of obstacles
    char obstacles;
    cin.get(obstacles);
    int numOfObstacles = ((int) obstacles - 48);
    // to ignore white space
    cin.ignore();
    if(numOfObstacles > 0){
        // for each obstacle:

        for(int i = 0; i < numOfObstacles; i++){
            //an obstacle string
            string object;
            getline (cin, object);

            vector<boost::any> parsedObstacle;
            parsedObstacle = parse.DataSplit(object);

            xObstacle = boost::any_cast<int>(parsedObstacle[0]);
            yObstacle = boost::any_cast<int>(parsedObstacle[1]);
            // set the grid position to hold an obstacle.
            grid->getState(xObstacle, yObstacle)->setIsObstacle(1);
        }
    }
    // call the menu for different input options
    Menu* menu = new Menu();
    menu->online(grid, socket);

    // frees memory before exiting the program.
    delete grid;
    delete menu;
    return 0;
}