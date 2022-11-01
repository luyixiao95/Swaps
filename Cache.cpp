//
// Created by Luyi Xiao on 10/30/22.
//

#include "Cache.h"


Cache::Cache(int s) {
    cacheSize = s;
    cache = vector<int>();
    cacheMap = map<int, int>();
    clockCache = vector<vector<int>>();
    clockPointer = 0;
}

int Cache::FIFO(int id) {

    if (cacheMap.count(id) > 0) {
        std::cout << "Hit:";
        for(int i : cache){
            std::cout << i << " " ;
        }
        //it's a hit
        return 1;
    }
    //it's a miss
    if (cache.size() < cacheSize) {
        //if the cache is not full
        cache.push_back(id);
        cacheMap.insert({id, id});
    }
    else {
        //if the cache is full
        int firstValue = cache[0];
        cache.erase(cache.begin());
        cacheMap.erase(firstValue);
        cache.push_back(id);
        cacheMap.insert({id, id});
    }

    std::cout << "Miss:";
    for(int i : cache){
        std::cout << i << " " ;
    }
    return 0;
}

int Cache::LRU(int id) {
    for (int i = 0; i < cache.size(); i ++) {

        if (cache[i] == id) {
            //IT'S A HIT
            cache.erase(cache.begin() + i);
            cache.push_back(id);
            std::cout << "Hit:";
            for(int i : cache){
                std::cout << i << " " ;
            }
            return 1;
        }
    }
        if (cache.size() < cacheSize) {
            cache.push_back(id);

        }
        else {
            cache.erase(cache.begin());
            cache.push_back(id);
        }

    std::cout << "Miss:";
    for(int i : cache){
        std::cout << i << " " ;
    }
        return 0;

}

int Cache::Clock(int id) {
    for (int i = 0; i < clockCache.size(); i ++) {

        if (clockCache[i][0] == id) {
            //IT'S A HIT
            clockCache[i][1] = 1;

            std::cout << "Hit:";
            for(vector<int> sub : clockCache){
                std::cout << sub[0] << " " ;
            }
            return 1;
        }

    }

    //it's a miss
    if (clockCache.size() < cacheSize) {
        clockCache.push_back(vector({id, 1}));
    }
    else {
        //Hit miss
        while (clockCache[clockPointer][1] == 1) {
            clockCache[clockPointer][1] = 0;
            clockPointer = (clockPointer + 1) % cacheSize;
        }

        clockCache.erase(clockCache.begin() + clockPointer);
        clockCache.push_back(vector({id, 1}));
    }
    std::cout << "Miss:";
    for(vector<int> sub : clockCache){
        std::cout << sub[0] << " " ;
    }

    return 0;
}

