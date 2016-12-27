cmake_minimum_required(VERSION 3.3)

project(Test)


include(CTest)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lpthread -std=c++0x")
set(test_SRCS Main.cpp BFSTest.cpp DriverTest.cpp GridTest.cpp LuxuryCabTest.cpp PassengerTest.cpp PointTest.cpp StandardCabTest.cpp StateTest.cpp TaxiCenterTest.cpp TripTest.cpp)
add_executable(runUnitTests gtest.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock core)
add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does.



