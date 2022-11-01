#include <iostream>
#include "Cache.h"
#include "System.h"
int main() {
    System system1 = System(vector{1, 2, 3, 4, 2, 5, 2, 3, 4, 2, 1, 2}, 0, 4);
    std::cout << "\n" << "Hitting rate is: " << system1.getHitRate() << "\n";

    System system2 = System(vector{1, 2, 3, 4, 2, 5, 2, 3, 4, 2, 1, 2}, 1, 4);
    std::cout << "\n" << "Hitting rate is: " << system2.getHitRate() << "\n";
    System system3 = System(vector{1, 2, 3, 4, 2, 5, 2, 3, 4, 2, 1, 2}, 2, 4);
    std::cout << "\n" << "Hitting rate is: " << system3.getHitRate();
    return 0;
}
