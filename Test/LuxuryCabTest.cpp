#include "gtest/gtest.h"
#include "../LuxuryCab.h"

using namespace std;

class LuxuryCabTest : public ::testing::Test {
protected:
    Point* p1;
    LuxuryCab* cab;
    State* location;
    State* dest;
    Color RED;
    Model HONDA;
    Grid* grid;

public:

    virtual void SetUp(){
        cout << "Setting up" << endl;
        p1 = new Point(0,0);
        dest = new State(Point(2,2),NULL,false);
        location = new State(*p1,NULL, false);
        vector<Point> route;
        cab = new LuxuryCab(12345, 0,RED, HONDA, 2, 2, location, false, route);
        grid = new Grid(4, 4);
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete p1;
        delete location;
        delete dest;
        delete cab;
        delete grid;
    }

    //constructor
    LuxuryCabTest() {}
};
//checks  getCab_ID function
TEST_F(LuxuryCabTest, getCab_ID_tester){

    ASSERT_EQ(cab->getCab_ID(),12345);
}
//checks getDistance_made function
TEST_F(LuxuryCabTest, getDistance_made_tester){

    ASSERT_EQ(cab->getDistance_made(),0);
}
//checks  getColor function
TEST_F(LuxuryCabTest, getColor_tester) {

    ASSERT_EQ(cab->getColor(), RED);
}
//checks  getModel function
TEST_F(LuxuryCabTest, getModel_tester) {

    ASSERT_NE(cab->getModel(), TESLA);
}
//checks  getSpeed function
TEST_F(LuxuryCabTest,getSpeed_tester) {

    ASSERT_EQ(cab->getSpeed(), 2);
}
//checks  getLocation function that the cab is on the beggining location(cause she didnt move since
//she was created
TEST_F(LuxuryCabTest,getLocation_tester) {

    ASSERT_EQ(location , cab->getLocation());
}
//checks setCab_ID function
TEST_F(LuxuryCabTest,setCab_ID_tester) {
    cab->setCab_ID(12223);
    ASSERT_EQ(cab->getCab_ID(), 12223);
}
//checks  setDistance_made function will set only positive int
TEST_F(LuxuryCabTest,setDistance_made_tester) {
    cab->setDistance_made(2);
    ASSERT_TRUE(cab->getDistance_made() >= 0);
}
//checks setColor function
TEST_F(LuxuryCabTest,setColor_tester) {
    cab->setColor(BLUE);
    ASSERT_TRUE(cab->getColor() == BLUE );
}
//checks  setModel function
TEST_F(LuxuryCabTest,setModel_tester) {
    cab->setModel(TESLA);
    ASSERT_TRUE(cab->getModel() == TESLA );
}
//checks  setLocation function
TEST_F(LuxuryCabTest,setLocation_tester) {
    cab->setLocation(NULL);
    ASSERT_TRUE(cab->getLocation() == NULL );
}

//checks  move function by seeing a diference in the location of the cab
TEST_F(LuxuryCabTest,move_tester) {
    cab->move(location,dest,grid);
    ASSERT_EQ(cab->getLocation()->getState().getX(),dest->getState().getX());
    ASSERT_EQ(cab->getLocation()->getState().getY(),dest->getState().getY());
}
