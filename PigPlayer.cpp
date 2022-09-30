//
// Created by Griffin Thompson on 9/29/22.
//

#include "PigPlayer.hpp"
#include <random>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
// no idea why it's freaking out about the generator not being
// seeded properly, since I'm using a random_device and everything.
PigPlayer::PigPlayer() {
    deferToOpponent = false;

    dieValue = 0;
    turnTotal = 0;
    gameTotal = 0;
    gen = std::mt19937(dev());
    distrib = std::uniform_int_distribution<>(1,6);
}
#pragma clang diagnostic pop


void PigPlayer::roll() {
    deferToOpponent = false; // if roll() is being called then we can assume it's this player's turn,
                             // no need to already be deferring
    int val = distrib(gen);
    if (val == 1) {
        resetTurnTotal();
        stop();
    }

    dieValue = val;
    turnTotal += dieValue;
}

void PigPlayer::stop() {
    deferToOpponent = true;
}

void PigPlayer::resetTurnTotal() {
    turnTotal = 0;
}

int PigPlayer::getDieValue() const {
    return dieValue;
}

int PigPlayer::getTurnTotal() const {
    return turnTotal;
}

int PigPlayer::getGameTotal() const {
    return gameTotal;
}

bool PigPlayer::defer() const {
    return deferToOpponent;
}

