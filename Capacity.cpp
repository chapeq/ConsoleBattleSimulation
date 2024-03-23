#include "Capacity.h"
#include <cstdlib>
#include <iostream>

Capacity::Capacity(int successRate, int chargeTurns)
    : mSuccessRate(successRate), mChargeTurns(0), mInitChargeTurns(chargeTurns), hasBeenUsed(false) {}


bool Capacity::useAbility() {
    if (mChargeTurns == 0) {
        mChargeTurns = mInitChargeTurns;
        if ((rand() % 100) < mSuccessRate) {
            hasBeenUsed = true;
            return true;
        }
        return false;
    }
    std::cout << "Tour(s) de charge restant(s) : " << mChargeTurns << std::endl;
    return false;
}


bool Capacity::resetAbility() {
    if (hasBeenUsed) {
        hasBeenUsed = false;
        return true;
    }
    return false;
}

void Capacity::decreaseChargeTurns() {
    if (mChargeTurns > 0) {
        mChargeTurns--;
    }
}