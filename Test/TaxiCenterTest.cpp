/**
 * The following class is used to test the Point class
 */
#include "gtest/gtest.h"
#include "../TaxiCenter.h"

using namespace std;

class TaxiCenterTest : public ::testing::Test {
protected:
    Point* p1;
    Point* p2;
    TaxiCenter center;
    State* state1;
    State* state2;
    Trip* trip;
    Grid* grid;
    StandardCab* cab;
    LuxuryCab* luxus;
    Passenger* customer;
    Driver* driver;
    Driver* driver2;


    virtual void SetUp(){
        cout << "Setting up" << endl;
        p1 = new Point(3,4);
        p2 = new Point(0,0);
        state1 = new State(*p1,NULL,true);
        state2 = new State(*p2,NULL,false);
        grid = new Grid(5,5);
        trip = new Trip(1,state1,state2,grid,2 ,40,1);
        cab = new StandardCab(12345, 0,RED, TESLA, 1, 1, state1, false);
        luxus = new LuxuryCab(12345, 0,WHITE, HONDA, 2, 2, state2,false);
        customer = new Passenger(state1,state2);
        driver = new Driver(123, 25, 5, 3.5, cab,  Single, NULL, false, 12345);
        driver2 = new Driver(123, 25, 5, 3.5, luxus,  Single, NULL,false, 12345);
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete p1;
        delete p2;
        delete driver;
        delete driver2;
        delete customer;
        delete luxus;
        delete cab;
        delete state1;
        delete state2;
        delete trip;
        delete grid;

    }
public:
    //constructor
    TaxiCenterTest() : center(){}
};
// checks that we get the right trip from "getTrips" function by adding a trip to center
// and checking that we get the right trip details
TEST_F(TaxiCenterTest, getTrips_tester) {
    center.AddTrip(trip);
    ASSERT_EQ(center.getTrips().at(0)->getdest()->getState().getX(), 0);
    ASSERT_EQ(center.getTrips().at(0)->getGrid()->getHeight(), 5);
    ASSERT_EQ(center.getTrips().at(0)->getStart()->getState().getX(), 3);
}
// checks that we get the right cab from "getTaxiCab" function by adding a Standard cab to center
// and checking that we get the right cab details
TEST_F(TaxiCenterTest, getTaxis_tester) {
    center.AddTaxiCab(cab);
    ASSERT_TRUE(center.getTaxis().at(0)->getCab_ID() >= 0);
    ASSERT_EQ(center.getTaxis().at(0)->getDistance_made(), 0);
    ASSERT_EQ(center.getTaxis().at(0)->getColor(), RED);
    ASSERT_EQ(center.getTaxis().at(0)->getLocation(), state1);
    ASSERT_EQ(center.getTaxis().at(0)->getModel(), TESLA);
    ASSERT_EQ(center.getTaxis().at(0)->getCoeficient(),1);
    ASSERT_EQ(center.getTaxis().at(0)->getSpeed(), 1);
}
// checks that we get the right cab from "getLuxTaxis" function by adding a luxury cab to center
// and checking that we get the right cab details
TEST_F(TaxiCenterTest, getLuxTaxis_tester) {
    center.AddTaxiLux(luxus);
    ASSERT_TRUE(center.getLuxTaxis().at(0)->getCab_ID() >= 0);
    ASSERT_EQ(center.getLuxTaxis().at(0)->getDistance_made(), 0);
    ASSERT_EQ(center.getLuxTaxis().at(0)->getColor(), WHITE);
    ASSERT_EQ(center.getLuxTaxis().at(0)->getLocation(), state2);
    ASSERT_EQ(center.getLuxTaxis().at(0)->getModel(), HONDA);
    ASSERT_EQ(center.getLuxTaxis().at(0)->getCoeficient(), 2);
    ASSERT_EQ(center.getLuxTaxis().at(0)->getSpeed(), 2);
}
// checks that we get the right driver from "getDrivers" function by adding a Driver to center and
// checking that we get the right driver details
TEST_F(TaxiCenterTest, getDrivers_tester) {
    center.AddDriver(driver);
    ASSERT_TRUE(center.getDrivers().at(0)->getId() >= 0);
    ASSERT_EQ(center.getDrivers().at(0)->getAge(), 25);
    ASSERT_EQ(center.getDrivers().at(0)->getExperience(), 5);
    ASSERT_EQ(center.getDrivers().at(0)->getSatisfaction(), 3.5);
    ASSERT_EQ(center.getDrivers().at(0)->getStatus(), Single);
    ASSERT_EQ(center.getDrivers().at(0)->getTaxiCabInfo(), cab);
}
// checks that we get the drivers location
TEST_F(TaxiCenterTest, standardCabLocationTest){
    center.AddTaxiCab(cab);
    center.AddDriver(driver);
    State* locat = cab->getLocation();
    int x = center.getDrivers().at(0)->getTaxiCabInfo()->getLocation()->getState().getX();
    ASSERT_TRUE(locat->getState().getX() == x);
}
/**
 * this fixture test function is used to check luxury cab location
*/
TEST_F(TaxiCenterTest, luxuryCabLocationTest){
    center.AddTaxiLux(luxus);
    center.AddDriver(driver2);
    State* locat = luxus->getLocation();
    int x = center.getDrivers().at(0)->getTaxiCabInfo()->getLocation()->getState().getX();
    ASSERT_TRUE(locat->getState().getX() == x);
}
/**
 * this fixture test function is used to check creation of trip
 */
TEST_F(TaxiCenterTest, tripCreatorTest){
    center.AddTaxiCab(cab);
    center.AddDriver(driver);
    center.tripCreator(trip);
    ASSERT_TRUE(driver->getTaxiCabInfo()->getLocation()->getState().getX() ==
                        trip->getdest()->getState().getX());
}
/*
 *checks that the adding standard cab function really adds a taxi to the vector of
 * standard taxis in center
 */
TEST_F(TaxiCenterTest, AddTaxi_Test){
    int a = center.getTaxis().size();
    center.AddTaxiCab(cab);
    int b = center.getTaxis().size();
    ASSERT_TRUE(a+1 == b);
}
/*
 *checks that the adding trips function really adds a trip to the vector of
 * trips in center
 */
TEST_F(TaxiCenterTest, AddTrip_Test){
    int a = center.getTrips().size();
    center.AddTrip(trip);
    int b = center.getTrips().size();
    ASSERT_TRUE(a+1 == b);
}
/*
 *checks that the adding driver function really adds a driver to the vector of
 * drivers in center
 */
TEST_F(TaxiCenterTest, AddDriver_Test){
    int a = center.getDrivers().size();
    center.AddDriver(driver);
    int b = center.getDrivers().size();
    ASSERT_TRUE(a+1 == b);
}
