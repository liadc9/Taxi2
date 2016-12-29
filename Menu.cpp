/**
 * The following class is used to hold all posssible menu options
 */
#include <iostream>
#include <fstream>
#include <sstream>
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
#include "Menu.h"
#include "Parser.h"
#include "Driver.h"
#include "State.h"
#include "Grid.h"
#include <boost/any.hpp>
#include <sys/socket.h>
#include "ITaxiCab.h"


using namespace std;

int id;
int age;
char status;
int expirience;
int vehicle;
int xStart;
int yStart;
int xEnd;
int yEnd;
int numPassengers;
double tariff;
int taxi_type;
char manufacturer;
char color;
int taxiID;




// creates new parser object
Parser parse;

// create a list of char data
vector<boost::any> parsedData;

/**
 * costrcutor for the menu
 */
Menu:: Menu(){

}
/**
 * The online function is called from the main class. it is used for the different options
 * that are possible by the taxi application.
 * press 1) adding a driver
 * press 2) adding a trip
 * press 3) adding a taxi
 * press 4) find driver location
 * press 6) get all drivers to destination
 * press 7 to quit
 * @param grid - our given grid created in main.
 */
void Menu:: online(Grid* grid, Socket* socket) {

    int choice = 0;
    TaxiCenter *taxiCenter;
    taxiCenter = new TaxiCenter();
    // while program doesn't terminate
    while(choice != 7) {
        // get user input for choice
        cin >> choice;
        string information;
        cin.ignore();
        switch (choice) {
            // create driver
            case 1 : {
                //create buffer
                char buffer[1024];
                // get nummber of drivers to input for server side
                cin >> choice;
                cin.ignore();

                // for each driver in each client send of buffer deserialize into driver.
                for(int i = 0; i < choice; i++) {
                    Driver *driver = new Driver(0, 0, 0, 0,NULL,
                            Marride,NULL, false, 0);
                    socket->reciveData(buffer, sizeof(buffer));
                    cout << buffer << endl;
                    /**
                     * deserialize buffer into driver object
                     */
                    string serial_str;
                    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
                    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
                    boost::archive::binary_iarchive ia(s2);
                    ia >> driver;

                    Status stat;
                    double satisfaction = 0;

                    //assign the driver the correct taxi according to vehicle id
                    for (int i = 0; i < taxiCenter->getTaxis().size(); i++) {
                        if (taxiCenter->getTaxis().at(i)->getCab_ID() == vehicle) {
                            taxiID = taxiCenter->getTaxis().at(i)->getCab_ID();
                            Driver *driver = new Driver(id, age, expirience, satisfaction,
                                                        taxiCenter->getTaxis().at(i), stat, NULL, false, taxiID);
                            // now the cab has a driver
                            taxiCenter->getTaxis().at(i)->setHasDriver(true);
                            taxiCenter->AddDriver(driver);
                            std::string serial_str;
                            /**
                             * serialize driver into buffer in order to send to client
                             */
                            boost::iostreams::back_insert_device<std::string> inserter(serial_str);
                            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
                            boost::archive::binary_oarchive oa(s);
                            oa << driver;
                            s.flush();
                            socket->sendData(serial_str);
                        }
                    }
                    //assign the driver the correct taxi according to vehicle id
                    for (int i = 0; i < taxiCenter->getLuxTaxis().size(); i++) {
                        if (taxiCenter->getLuxTaxis().at(i)->getCab_ID() == vehicle) {
                            taxiID = taxiCenter->getLuxTaxis().at(i)->getCab_ID();
                            Driver *driver = new Driver(id, age, expirience, satisfaction,
                                                        taxiCenter->getTaxis().at(i), stat, NULL, false, taxiID);
                            // now the cab has a driver
                            taxiCenter->getLuxTaxis().at(i)->setHasDriver(true);
                            taxiCenter->AddDriver(driver);
                            int idCab = driver->getTaxiCabInfo()->getCab_ID();

                            /**
                             * serialize driver into buffer in order to send to client
                             */
                            std::string serial_str;
                            boost::iostreams::back_insert_device<std::string> inserter(serial_str);
                            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
                            boost::archive::binary_oarchive oa(s);
                            oa << driver;
                            s.flush();
                            socket->sendData(serial_str);

                            /*
                             * send the client the trip
                             */
                            for (int i = 0; i < taxiCenter->getTrips().size(); i++) {



                                Trip *trip = taxiCenter->getTrips().at(i);
                                // call trip creator for the driver to send him to final location
                                taxiCenter->tripCreator(trip);
                            }


                        }
                    }

                }
                break;

            }
            // creaete a trip
            case 2 : {
                getline(cin, information);
                parsedData = parse.DataSplit(information);

                // handle all info from the parser
                id = boost::any_cast<int>(parsedData[0]);
                xStart = boost::any_cast<int>(parsedData[1]);
                yStart = boost::any_cast<int>(parsedData[2]);
                xEnd = boost::any_cast<int>(parsedData[3]);
                yEnd = boost::any_cast<int>(parsedData[4]);
                numPassengers = boost::any_cast<int>(parsedData[5]);
                tariff = boost::any_cast<double>(parsedData[6]);

                State *start = new State(Point(xStart, yStart), NULL, false);
                State *end = new State(Point(xEnd, yEnd), NULL, false);
//change 1 to the real time of start that we get from the terminal
                // create trip accroding to all info
                Trip *trip = new Trip(id, start, end, grid, numPassengers, tariff,1);
                taxiCenter->AddTrip(trip);
                break;
            }
            // create a cab
            case 3 : {
                getline(cin, information);
                parsedData = parse.DataSplit(information);

                Model enumModel;
                Color enumColor;

                // get all data from parser accordingly
                id = boost::any_cast<int>(parsedData[0]);
                taxi_type = boost::any_cast<int>(parsedData[1]);
                manufacturer = boost::any_cast<char>(parsedData[2]);
                color = boost::any_cast<char>(parsedData[3]);

                if (manufacturer == 'H') {
                    enumModel = HONDA;
                } else if (manufacturer == 'S') {
                    enumModel = SUBARU;
                } else if (manufacturer == 'T') {
                    enumModel = TESLA;
                } else if (manufacturer == 'F') {
                    enumModel = FIAT;
                }

                if (color == 'R') {
                    enumColor = RED;
                } else if (color == 'B') {
                    enumColor = BLUE;
                } else if (color == 'G') {
                    enumColor = GREEN;
                } else if (color == 'P') {
                    enumColor = PINK;
                } else if (color == 'W') {
                    enumColor = WHITE;
                }

                State *location = new State(Point(0,0), NULL, false);

                // create cab according to the data
                if (taxi_type == 1) {
                    StandardCab *cab = new StandardCab(id, 0, enumColor, enumModel, taxi_type, 0, location, false);
                    taxiCenter->AddTaxiCab(cab);
                } else {
                    LuxuryCab *lCab = new LuxuryCab(id, 0, enumColor, enumModel, taxi_type, 0, location, false);
                    taxiCenter->AddTaxiLux(lCab);
                }

                break;
            }
            case 4 : {
                // find driver positon
                int cabDriver;
                cin >> cabDriver;
                // get the driver accorind to id.
                ITaxiCab *cablocate = taxiCenter->getDrivers().at((unsigned int) cabDriver)->getTaxiCabInfo();
                int x = cablocate->getLocation()->getState().getX();
                int y = cablocate->getLocation()->getState().getY();

                Point *pos = new Point(x, y);

                cout << *pos << endl;

                delete pos;
                break;
            }
            case 6 : {
                // get all drivers to final postion
                for (int i = 0; i < taxiCenter->getTrips().size(); i++) {
                    Trip *trip = taxiCenter->getTrips().at(i);
                    // call trip creator for the driver to send him to final location
                    taxiCenter->tripCreator(trip);
                }
                break;
            }
            case 9 : {



            }
            // no default requirement
        }
    }
    // remove all taxis from memory if 7 is pressed
    for(int i = taxiCenter->getTaxis().size(); i >0; i--){
        StandardCab* cab = taxiCenter->getTaxis().at(i-1);
        delete cab;
        taxiCenter->getTaxis().pop_back();
    }
    // remove all luxury taxis from memory if 7 is pressed
    for(int i = taxiCenter->getLuxTaxis().size(); i >0; i--){
        LuxuryCab* cab = taxiCenter->getLuxTaxis().at(i-1);
        delete cab;
        taxiCenter->getLuxTaxis().pop_back();
    }

    // remove all drivers from memory if 7 is pressed
    for(int i = taxiCenter->getDrivers().size(); i >0; i--){
        Driver* driver = taxiCenter->getDrivers().at(i-1);
        delete driver;
        taxiCenter->getDrivers().pop_back();
    }
    // remove all trips from memory if 7 is pressed
    for(int i = taxiCenter->getTrips().size(); i >0; i--){
        Trip* trip = taxiCenter->getTrips().at(i-1);
        delete trip->getStart();
        delete trip->getdest();
        delete trip;
        taxiCenter->getTrips().pop_back();
    }
    delete taxiCenter;



};


/*
 * old parser for case 1:
                    //getline(cin, information);
                    parse the data given
                    parsedData = parse.DataSplit(buffer);


                    // properly receive all data from parser
                    id = boost::any_cast<int>(parsedData[0]);
                    age = boost::any_cast<int>(parsedData[1]);
                    status = boost::any_cast<char>(parsedData[2]);

                    if (status == 'S') {
                        stat = Single;
                    } else if (status == 'M') {
                        stat = Marride;
                    } else if (status == 'D') {
                        stat = Divorced;
                    } else if (status == 'W') {
                        stat = Widowed;
                    }

                    expirience = boost::any_cast<int>(parsedData[3]);
                    vehicle = boost::any_cast<int>(parsedData[4]);
                    */