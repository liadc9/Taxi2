#include "gtest/gtest.h"

#include "../Trip.h"

#include "../Grid.h"
#include "../State.h"

using namespace std;

class TripTest : public ::testing::Test {
protected:
    Point* p1;
    Point* p2;
    Trip trip1;
    Trip trip2;
    State* state1;
    State* state2;
    Grid* grid;
    Grid* grid2;
public:
    virtual void SetUp(){
        cout << "Setting up" << endl;
        p1= new Point(1,2);
        p2= new Point(2,2);
        state1 = new State(*p1,NULL,true);
        state2 = new State(*p2,NULL,false);
        grid = new Grid(4, 4);
        grid2 = new Grid(5, 4);
    }

    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete p1;
        delete p2;
        delete state1;
        delete state2;
        delete grid;
        delete grid2;
    }
    //constructor
    TripTest() : trip1(0, state1,state2,grid,2,40) , trip2(state2,state1,grid){}
};/*
//checks getStart function by comparing two different start points of tow trips
TEST_F(TripTest, getStart_test){
    ASSERT_TRUE(trip1.getStart()->getState().getX() != trip2.getStart()->getState().getX());
}
//checks getdest function by comparing two different end points of tow trips
TEST_F(TripTest, getdest_test1){
    ASSERT_EQ(trip1.getdest()->getState().getY() , trip2.getdest()->getState().getY());
}*/
//checks getStart function by comparing the grids of tow trips
TEST_F(TripTest, name_of_test2){
    ASSERT_TRUE(trip1.getGrid() == trip2.getGrid());
}
//checks getRide_id by checking its not negetive
TEST_F(TripTest,  getRide_id_test){
    ASSERT_FALSE(trip1.getRide_id() < 0);
}
//checks getNumOfPassengers function by checking its bigger than 0
TEST_F(TripTest, getNumOfPassengers_test1){
    ASSERT_TRUE(trip1.getNumOfPassengers() > 0);
}
//checks getTariff function by checking that its not negetive
TEST_F(TripTest,getTariff_test){
    ASSERT_NE(trip1.getTariff() , -12);
}
//checks getMeter_passed function by checking that its not negetive
TEST_F(TripTest, getMeter_passed_test2){
    ASSERT_NE(trip1.getMeter_passed() , -10);
}
//checks setRide_id function
TEST_F(TripTest,  setRide_id_test2){
    trip1.setRide_id(234);
    ASSERT_EQ(trip1.getRide_id(),234);
}
//checks setNumOfPassengers function
TEST_F(TripTest, setNumOfPassengers_test2){
    trip1.setNumOfPassengers(2);
    ASSERT_EQ(trip1.getNumOfPassengers(),2);
}
//checks setTariff function
TEST_F(TripTest, setTariff_test2){
    trip1.setTariff(2);
    ASSERT_EQ(trip1.getTariff(),2);
}
//checks setMeter_passed function
TEST_F(TripTest, setMeter_passed_test2){
    trip1.setMeter_passed(10);
    ASSERT_EQ(trip1.getMeter_passed(),10);
}
//checks setStart function
TEST_F(TripTest, setStart_test2){
    trip1.setStart(trip2.getStart());
    ASSERT_TRUE(trip1.getStart() == trip2.getStart());
}
//checks setStop function
TEST_F(TripTest, setStop_test2){
    trip1.setStop(trip2.getdest());
    ASSERT_TRUE(trip1.getdest() == trip2.getdest());
}
//checks setGrid function by changing the grid width
TEST_F(TripTest, setGrid_test2){
    trip1.setGrid(grid2);
    ASSERT_EQ(trip1.getGrid()->getWidth(), 5);
}


