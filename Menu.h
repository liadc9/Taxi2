//
// Created by liad on 13/12/16.
//

#ifndef TAXI_MENU_H
#define TAXI_MENU_H
#include "Grid.h"
#include "Driver.h"
#include "Socket.h"

class Menu {
public:
    Menu();
    void online(Grid* grid,Socket* socket);
};


#endif //TAXI_MENU_H
