/**
 * This is the Client side application
 */
#include <cstdlib>
#include <boost/any.hpp>
#include "Socket.h"
#include "Udp.h"
#include "Parser.h"
#include "Driver.h"
#include "Client.h"


using namespace std;
/**
 * The following method is th main method of the client side
 * it is used to initialize a client connection,
 * parse from user input driver info, serialize info,
 * and send the server side the serialized info.
 * the client expects to receive the corrcet vehicle
 * and is updates everytime there is movement on the grid
 * @param argc - num of args
 * @param argv - recevied args, the port num
 * @return
 */
int main2(int argc, char *argv[]) {
    int id;
    int age;
    char status;
    int expirience = 0;
    int vehicle;
    int taxi_type;
    int taxiID;
    char buffer[1024];


    Socket* client = new Udp(false, atoi(argv[1]));
    client->initialize();

    // get driver input from user
    string driverString;
    getline (cin, driverString);

    // creates new parser object
    Parser parse;

    // create a list of int data
    vector<boost::any> parsedData;

    parsedData = parse.DataSplit(driverString);

    Status stat;

    // properly reeive all data from parser
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
    double satisfaction = 0;
    taxiID = -1;

    //serialize
    Driver *driver = new Driver(id, age, expirience, satisfaction,
                                NULL, stat, NULL, false, taxiID);

    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << driver;
    s.flush();
    client->sendData(serial_str);
    serial_str.clear();


//deserialize to taxi
    ITaxiCab* taxi;
    client->reciveData(buffer, sizeof(buffer));
    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> taxi;
    serial_str.clear();

///*******************8888888888//////
bool go = false;
while( go == false) {
        std::string sttt = "waiting for trip";
        client->sendData(sttt);
        //deserialize to trip
    /*    client->reciveData(buffer, sizeof(buffer));
        Trip *trip;
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device);
        ia >> trip;
        serial_str.clear();
*/
        while (driver->isOnTrip() == true) {
            go = true;
            string serial2_str;
            boost::iostreams::back_insert_device<std::string> inserter(serial2_str);
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
            boost::archive::binary_oarchive oa(s);
            oa << go;
            s.flush();
            client->sendData(serial2_str);
            serial2_str.clear();
            Point *location;
            client->reciveData(buffer, sizeof(buffer));
            boost::iostreams::basic_array_source<char> device(serial2_str.c_str(), serial2_str.size());
            boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
            boost::archive::binary_iarchive ia(s2);
            ia >> location;
            taxi->getLocation()->getState().setX(location->getX());
            taxi->getLocation()->getState().setY(location->getY());
        }

}

}
