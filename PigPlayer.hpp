//
// Created by Griffin Thompson on 9/29/22.
//

#ifndef INC_04L_PIG_GAME_PIGPLAYER_HPP
#define INC_04L_PIG_GAME_PIGPLAYER_HPP

#include <random>

class PigPlayer {
private:
    bool deferToOpponent;

    int dieValue;
    int turnTotal;
    int gameTotal;

    std::random_device dev = ;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;


public:
    void roll();
    void stop();
    void resetTurnTotal();

    int getDieValue() const;
    int getTurnTotal() const;
    int getGameTotal() const;

    bool defer() const;

    PigPlayer();
};


#endif //INC_04L_PIG_GAME_PIGPLAYER_HPP
