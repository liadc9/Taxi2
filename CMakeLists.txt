cmake_minimum_required(VERSION 3.6)
project(Taxi)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


include_directories("/home/liad/.linuxbrew/Cellar/boost/1.62.0/include")
set(BOOST_ROOT "/home/liad/.linuxbrew/Cellar/boost/1.62.0/include")
set(Boost_Path "/home/liad/.linuxbrew/Cellar/boost/1.62.0/include")

set(Boost_INCLUDE_DIR "${Boost_Path}/boost")

#include_directories("/Users/liad/Downloads/boost_1_62_0")

#set(BOOST_ROOT "/Users/liad/Downloads/boost_1_62_0")
#set(Boost_Path "/Users/liad/Downloads/boost_1_62_0")

#set(Boost_INCLUDE_DIR "${Boost_Path}/boost_1_62_0")

#include_directories("../Cellar/boost/1.62.0/include/boost")

#set(BOOST_ROOT "../Cellar/boost/1.62.0/include/boost")
#set(Boost_Path "../Cellar/boost/1.62.0/include/boost")

#find_package(Boost 1.62.0 COMPONENTS system filesystem REQUIRED)

#if(Boost_FOUND)

    #message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    #message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    #message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    #include_directories(${Boost_INCLUDE_DIRS})

#endif()

set(SOURCE_FILES Main.cpp Point.cpp Point.h
        Grid.h Grid.cpp BFS.h BFS.cpp ISearchable.h ISearchable.cpp Main.h
        Parser.h Parser.cpp State.h State.cpp Trip.h Trip.cpp Test/PointTest.cpp
        Driver.cpp Driver.h ITaxiCab.h ITaxiCab.cpp Test/TaxiCenterTest.cpp Waze.cpp Waze.h
        LuxuryCab.cpp LuxuryCab.h Map.cpp Map.h Passenger.cpp Passenger.h StandardCab.cpp
        StandardCab.h TaxiCenter.cpp TaxiCenter.h Test/TripTest.cpp Test/StateTest.cpp
        Test/GridTest.cpp Test/StandardCabTest.cpp Test/LuxuryCabTest.cpp Test/BFSTest.cpp
        Test/PassengerTest.cpp Test/DriverTest.cpp Menu.cpp Menu.h)
add_executable(Taxi ${SOURCE_FILES} Test/PointTest.cpp)
target_link_libraries(Taxi gtest gtest_main)

#if(Boost_FOUND)

    #target_link_libraries(BoostTest ${Boost_LIBRARIES})

#endif()