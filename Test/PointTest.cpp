/**
 * The following class is used to test the Point class
 */
#include "gtest/gtest.h"
#include "../Point.h"

using namespace std;

class PointTest : public ::testing::Test {
protected:
    Point p1;
    Point p2;
    Point p3;

    virtual void SetUp(){
        cout << "Setting up" << endl;
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
    }
public:
    //constructor
    PointTest() : p1(1,2) , p2(3,4), p3(0,0){}
};
/**
 * this fixture test function is used to check getter of x
 */
TEST_F(PointTest, X_tester){
    int x = 1;
    ASSERT_EQ(p1.getX(), x);
}
/**
 * this fixture test function is used to check getter of y
 */
TEST_F(PointTest, y_tester){
    int y = 2;
    ASSERT_EQ(p1.getY(), y);
}
/**
 * this fixture test function is used to check two points
 */
TEST_F(PointTest, two_points_test){

    ASSERT_NE(p1.getY(), p2.getY());
}
/**
 * this fixture test function is used to simple constructor
 */
TEST_F(PointTest, simple_constructor){

    ASSERT_EQ(p3.getX(), p3.getY());
}
/**
 * this fixture test function is used to check getter of x
 */
TEST_F(PointTest, getterTestX){
    int x = 5;
    p3.setX(5);
    ASSERT_EQ(p3.getX(),x);
}
/**
 * this fixture test function is used to check getter of y
 */
TEST_F(PointTest, getterTestY){
    int y = 3;
    p3.setY(3);
    ASSERT_EQ(p3.getY(),y);
}
/**
 * this fixture test function is used to check the printing
 */
TEST_F(PointTest, PrintingTest){
    stringstream buffer;
    buffer <<p1;
    buffer.str();
    ASSERT_EQ(buffer.str(), "(1,2)");
}

