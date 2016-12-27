#include "gtest/gtest.h"
#include "../State.h"

using namespace std;

class StateTest : public ::testing::Test {
protected:
    State* state1;
    State state2;
    State* state3;
public:

    virtual void SetUp(){
        cout << "Setting up" << endl;
        state1 = new State(Point(3,4),NULL,true);
        state3 = new State(Point(0,0),NULL,false);
    }

    virtual void TearDown() {
        cout << "Tearing down" << endl;
        delete state1;
        delete state3;
    }
    StateTest() : state2(Point(4,4),NULL,false){}
};

TEST_F(StateTest, name_of_test){
    ASSERT_EQ(state1->getComeFrom(), state2.getComeFrom());
}

TEST_F(StateTest, name_of_test2){
    ASSERT_NE(state1->getState().getX(), state2.getState().getX());
}


TEST_F(StateTest, name_of_test3){
    ASSERT_EQ(state1->getState().getY(), state2.getState().getY());
}

TEST_F(StateTest, name_of_test4){
    ASSERT_NE(state1->getWasHere(), state2.getWasHere());
}

TEST_F(StateTest, SETWASHERE_CHECK){
    state1->setWasHere(false);
    ASSERT_NE(state1->getWasHere(), true);
}
TEST_F(StateTest,set_come_from ){
    state1->setComeFrom(state3);
    ASSERT_TRUE(state1->getComeFrom() == state3);
}
TEST_F(StateTest, set_state){
    Point p = Point(1,1);
    state1->setState(p);
    ASSERT_EQ(state1->getState().getX(),1 );
    ASSERT_EQ(state1->getState().getY(),1 );
}

TEST_F(StateTest, compare){
    ASSERT_EQ(state1->Comparison(state2), false);
}
