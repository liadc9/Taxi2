/**
 * The following class is used to test the BFS class
 */
#include <gmock/gmock-matchers.h>
#include "gtest/gtest.h"
#include "../Point.h"
#include "../Trip.h"
#include "../Grid.h"
#include "../BFS.h"
#include "../ISearchable.h"


using namespace std;

class BFSTest : public ::testing::Test {
protected:
    Trip* trip1;
    State* start1;
    State* end1;
    Grid* grid1;
    BFS* bfs1;

    Trip* trip2;
    State* start2;
    State* end2;
    BFS* bfs2;

    Grid* grid2;
    Trip* trip3;
    State* start3;
    State* end3;
    BFS* bfs3;


    virtual void SetUp(){
        cout << "Setting up" << endl;
        start1 = new State(Point(0,0),NULL,false);
        end1 = new State(Point(2,2),NULL,false);
        grid1 = new Grid(3,3);
        trip1 = new Trip(start1, end1, grid1);
        bfs1 = new BFS(trip1);

        start2 = new State(Point(2,2),NULL,false);
        end2 = new State(Point(0,0),NULL,false);
        trip2 = new Trip(start2, end2, grid1);
        bfs2 = new BFS(trip2);

        grid2 = new Grid(9,9);
        start3 = new State(Point(5,5),NULL,false);
        end3 = new State(Point(0,0),NULL,false);
        trip3 = new Trip(start3, end3, grid2);
        bfs3 = new BFS(trip3);
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete grid1;
        delete grid2;

        delete start1;
        delete end1;
        delete trip1;
        delete bfs1;

        delete start2;
        delete end2;
        delete trip2;
        delete bfs2;

        delete start3;
        delete end3;
        delete trip3;
        delete bfs3;
    }
public:
    //constructor
    BFSTest() {}
};
/**
 * this fixture test function is used to check a simple BFS route
 */
TEST_F(BFSTest, simpleRouteTester){
    vector<Point> route = bfs1->AlgoRun();
    vector<Point> check;
    check.push_back(Point(0,0));
    check.push_back(Point(0,1));
    check.push_back(Point(0,2));
    check.push_back(Point(1,2));
    check.push_back(Point(2,2));
    for(int i = 0; i < route.size(); i++)
    {
        ASSERT_EQ(route.at(i).getX(),check.at(i).getX());
        ASSERT_EQ(route.at(i).getY(),check.at(i).getY());
    }
}
/**
 * this fixture test function is used to check a reverse BFS route to the first
 */
TEST_F(BFSTest, ReverseRouteTester){
    vector<Point> route = bfs2->AlgoRun();
    vector<Point> check;
    check.push_back(Point(2,2));
    check.push_back(Point(1,2));
    check.push_back(Point(0,2));
    check.push_back(Point(0,1));
    check.push_back(Point(0,0));

    for(int i = 0; i < route.size(); i++)
    {
        ASSERT_EQ(route.at(i).getX(),check.at(i).getX());
        ASSERT_EQ(route.at(i).getY(),check.at(i).getY());
    }
}
/**
 * this fixture test function is used to check a bigger route
 */
TEST_F(BFSTest, nineninegrid55to00RouteTester){
    vector<Point> route = bfs3->AlgoRun();
    vector<Point> check;
    check.push_back(Point(5,5));
    check.push_back(Point(4,5));
    check.push_back(Point(3,5));
    check.push_back(Point(2,5));
    check.push_back(Point(1,5));
    check.push_back(Point(0,5));
    check.push_back(Point(0,4));
    check.push_back(Point(0,3));
    check.push_back(Point(0,2));
    check.push_back(Point(0,1));
    check.push_back(Point(0,0));

    for(int i = 0; i < route.size(); i++)
    {
        ASSERT_EQ(route.at(i).getX(),check.at(i).getX());
        ASSERT_EQ(route.at(i).getY(),check.at(i).getY());
    }
}

