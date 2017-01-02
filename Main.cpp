/**
 * This is the main Class which is used in order to run the BFS algorithm on the grid.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Point.h"
#include <iostream>
#include <vector>
#include <string>
#include "src/Parser.h"
#include "src/Trip.h"
#include "src/Grid.h"
#include "src/BFS.h"
#include "src/TaxiCenter.h"
#include <boost/any.hpp>
#include "src/Menu.h"
#include "src/sockets/Udp.h"
//#include <gtest/gtest.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/export.hpp>

using namespace std;

BOOST_CLASS_EXPORT_GUID(StandardCab,"StandardCab")
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
    Socket* socket = new Udp(true,1212);
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
    //close the socket
    socket->closeData();

    // frees memory before exiting the program.
    delete grid;
    delete menu;
    return 0;
}