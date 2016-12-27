//
// Created by gal on 02/12/16.
//

/**
 * The following class is used to test the Point class
 */
#include "gtest/gtest.h"
#include "../Passenger.h"

using namespace std;

class PassengerTest : public ::testing::Test {
protected:
    Point* p1;
    Point* p2;
    Point* p3;
    State* state1;
    State* end1;
    State* state3;
    Passenger customer;
    TaxiCenter* taxiCenter;

    virtual void SetUp(){
        cout << "Setting up" << endl;
        p1 = new Point(0,0);
        p2 = new Point(0,2);
        p3 = new Point(0,1);
        state1 = new State(*p1,NULL,false);
        end1 = new State(*p2,NULL,false);
        state3 = new State(*p3,NULL,false);
        taxiCenter = new TaxiCenter();
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete p1;
        delete p2;
        delete p3;
        delete state1;
        delete end1;
        delete state3;
        delete taxiCenter;
    }
public:
    //constructor
    PassengerTest() : customer(state1,end1) {}
};
//check getStart_point function is not null
TEST_F(PassengerTest, getStart_point_tester){
    ASSERT_TRUE(customer.getStart_point()!= NULL);
}
//check getEnd_point function
TEST_F(PassengerTest, getEnd_point_tester){
    ASSERT_EQ(customer.getEnd_point()->getState().getX(), end1->getState().getX());
    ASSERT_EQ(customer.getEnd_point()->getState().getY(), end1->getState().getY());

}
//check setStart_point function
TEST_F(PassengerTest, setStart_point_tester){
    customer.setStart_point(state3);
    ASSERT_EQ(customer.getStart_point(), state3);
}
//check setEnd_point function
TEST_F(PassengerTest, setEnd_point_tester){
    customer.setEnd_point(state3);
    ASSERT_EQ(customer.getEnd_point(), state3);
}
