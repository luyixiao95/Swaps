//
// Created by Luyi Xiao on 10/31/22.
//

#include "System.h"
#include "Cache.h"

System::System(vector<int> stream, int sType, int cSize) : cache(cache) {
    hitNumber = 0;
    missNumber = 0;
    streamNumber = stream.size();
    swapType = sType;
    cache = Cache(cSize);
    idStream = stream;
    if (swapType == 0) {

        for (int i : idStream) {

            int res = cache.FIFO(i);
            res == 0 ? missNumber ++: hitNumber ++;
        }
    }

    else if (swapType == 1) {

        for (int i : idStream) {

            int res = cache.LRU(i);
            res == 0 ? missNumber ++: hitNumber ++;
        }
    }
    else if (swapType == 2) {

        for (int i : idStream) {

            int res = cache.Clock(i);
            res == 0 ? missNumber ++: hitNumber ++;
        }
    }

}

float System::getHitRate() {
    return float(hitNumber) / float(streamNumber);
}
