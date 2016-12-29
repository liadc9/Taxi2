/**
 * The following class is used to test the Driver class
 */
#include "gtest/gtest.h"
#include "../Driver.h"
#include "../StandardCab.h"
#include "../LuxuryCab.h"

using namespace std;

class DriverTest : public ::testing::Test {
protected:
    Driver driver;
    StandardCab* taxiCab;
    Point* p1;
    Point* p2;
    Point* p3;
    State* state1;
    State* end1;
    State* location;
    Passenger* customer;
    Color RED;
    Model HONDA;
    Status Single;
    LuxuryCab* taxiCab2;


    virtual void SetUp(){
        cout << "Setting up" << endl;
        p3 = new Point(0,0);
        p2 = new Point(0,2);
        p1 = new Point(0,0);
        state1 = new State(*p1,NULL,false);
        end1 = new State(*p2,NULL,false);
        location = new State(*p1,NULL, false);
        taxiCab = new StandardCab(12345, 0,RED, HONDA, 1, 1, location, false);
        taxiCab2 = new LuxuryCab(12345, 1,RED, HONDA, 2, 2, location, false);
        customer= new Passenger(state1,end1);
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete p3;
        delete p2;
        delete p1;
        delete state1;
        delete end1;
        delete location;
        delete taxiCab;
        delete taxiCab2;
        delete customer;
    }
public:
    //constructor
    DriverTest() : driver(12345, 25, 5, 3.5, taxiCab,  Single, customer, false, 12345) {}
};
//checks getId function
TEST_F(DriverTest, getId_tester){
    int x = 12345;
    ASSERT_EQ(driver.getId(), x);
}
//checks getAge function
TEST_F(DriverTest, getAge_tester){
    int x = 25;
    ASSERT_EQ(driver.getAge(), x);
}
//checks getExpirience function
TEST_F(DriverTest, getExpirience_tester){
    int x = 5;
    ASSERT_EQ(driver.getExperience(), x);
}
//checks getSatisfaction function
TEST_F(DriverTest, getSatisfaction_tester){
    double y = 3.5;
    ASSERT_EQ(driver.getSatisfaction(), y);
}
//checks getTaxiCabInfo function by comparing pointers to taxiCab object
TEST_F(DriverTest, getTaxiCabInfo_tester){
    ASSERT_TRUE(driver.getTaxiCabInfo()->getModel()== HONDA);
    ASSERT_TRUE(driver.getTaxiCabInfo()->getColor() == RED);
    ASSERT_NE(driver.getTaxiCabInfo()->getCoeficient() , taxiCab->getCoeficient());

}
//checks getSatus function by checking it doesnt get an different enum type
TEST_F(DriverTest, getStatus_tester){
    ASSERT_TRUE(driver.getStatus() == Single);
}
//checks getSatisfaction function by checking "driver" pointer to Passenger object
TEST_F(DriverTest, getCustomer_tester){
    ASSERT_EQ(customer->getEnd_point()->getState().getX(),driver.getCustomer()->getEnd_point()->getState().getX());
}
//checks setId function
TEST_F(DriverTest, setId_tester){
    driver.setId(333);
    ASSERT_EQ(driver.getId(), 333);
}
//checks setAge function
TEST_F(DriverTest, setAge_tester){
    driver.setAge(33);
    ASSERT_EQ(driver.getAge(), 33);
}
//checks setExpirience function
TEST_F(DriverTest, setExpirience_tester){
    driver.setExperience(10);
    ASSERT_EQ(driver.getExperience(), 10);
}
//checks setSatisfaction function
TEST_F(DriverTest, setSatisfaction_tester){
    driver.setSatisfaction(3);
    ASSERT_EQ(driver.getSatisfaction(), 3);
}
//checks setStatus function
TEST_F(DriverTest, setStatus_tester){
    driver.setStatus(Widowed);
    ASSERT_EQ(driver.getStatus(), Widowed);
}
//checks setCustomer function
TEST_F(DriverTest, setCustomer_tester){
    driver.setCustomer(NULL);
    ASSERT_TRUE(driver.getCustomer() == NULL);
}
//checks setTaxiCabInfo function
TEST_F(DriverTest, setTaxiCabInfo_tester){
    driver.setTaxiCabInfo(taxiCab2);
    ASSERT_EQ(driver.getTaxiCabInfo(), taxiCab2);
}
