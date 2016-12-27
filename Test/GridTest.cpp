#include "gtest/gtest.h"
#include "../Grid.h"

using namespace std;

class GridTest : public ::testing::Test {
protected:
    Point* p1;
    Point* p2;
    Point* p4;
    Grid* grid1;
    State* stat1;
public:
    virtual void SetUp(){
        cout << "Setting up" << endl;
        p1 = new Point(0,0);
        p2 = new Point(1,0);
        p4 = new Point(0,1);
        stat1 = new State(*p1,NULL,false);
        grid1 = new Grid(2,3);
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete p1;
        delete p2;
        delete p4;
        delete stat1;
        delete grid1;
    }

};
//checks gridHight function
TEST_F(GridTest, gridHight){
    ASSERT_EQ(grid1->getHeight(), 3);
}
//checks gridWidth function
TEST_F(GridTest, gridWidth){
    ASSERT_EQ(grid1->getWidth(), 2);
}
//checks getSizes function
TEST_F(GridTest, getSizes){
    //check the dim
    int a = grid1->getSizes().size();
    ASSERT_NE(a , 3);
    //check that we get width at firs and then the height
    ASSERT_EQ(grid1->getSizes().at(0) , 2);
    ASSERT_EQ(grid1->getSizes().at(1) , 3);
}
//checks setWasHere function that she chancge the state in the(x,y) place to be false
TEST_F(GridTest, setWasHere){
    grid1->setWasHere(1,1);
    ASSERT_EQ(grid1->getState(1,1)->getWasHere(), true);
}
//checks getStateCheck function that she returns a pointer to the(x,y) place in the grid
TEST_F(GridTest, getStateCheck){
    ASSERT_TRUE(grid1->getState(1,0)->getState().getX() == 1);
}
//checks get_neighbor function that she by checking the neibors of the state
TEST_F(GridTest, get_neibors_check){
    if(grid1->get_neighbor(stat1,grid1).size() > 0){
        ASSERT_EQ(grid1->get_neighbor(stat1,grid1).at(0)->getState().getX(), p4->getX());
        ASSERT_EQ(grid1->get_neighbor(stat1,grid1).at(1)->getState().getX(), p2->getX());
        ASSERT_EQ(grid1->get_neighbor(stat1,grid1).at(0)->getState().getY(), p4->getY());
        ASSERT_EQ(grid1->get_neighbor(stat1,grid1).at(1)->getState().getY(), p2->getY());
    }

}
