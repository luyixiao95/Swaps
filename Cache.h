//
// Created by Luyi Xiao on 10/30/22.
//

#ifndef SWAPS_CACHE_H
#define SWAPS_CACHE_H
using namespace std;

#include <iostream>
#include <vector>
#include <map>


class Cache {
private:
    int cacheSize;
    vector<int> cache;
    map<int, int> cacheMap;
    vector<vector<int>> clockCache;
    int clockPointer;
public:
    explicit Cache(int s);
    int FIFO(int id);
    int LRU(int id);
    int Clock(int id);
};


#endif //SWAPS_CACHE_H
