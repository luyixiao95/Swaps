//
// Created by Luyi Xiao on 10/31/22.
//

#ifndef SWAPS_SYSTEM_H
#define SWAPS_SYSTEM_H


#include <iostream>
#include <vector>
#include <map>
#include "Cache.h"
using namespace std;

class System {
private:
    int hitNumber;
    int missNumber;
    int streamNumber;
    int swapType;
    Cache cache;
    vector<int> idStream;
public:
    System(vector<int> stream, int sType, int cSize);
    float getHitRate();

};


#endif //SWAPS_SYSTEM_H
