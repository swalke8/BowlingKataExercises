/* 
 * File:   Game.cpp
 * Author: Swalker
 * 
 * Created on March 9, 2011, 10:28 AM
 */

#include "Game.h"

Game::Game() {
    myScore = 0;
    currentRoll = 0;
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::roll(int pins) {
    rolls[currentRoll++] = pins;
}

int Game::score() {
    int frameIndex = 0;
    for (int frame = 0; frame < 10; frame++)
    {
        if (isStrike(frameIndex))
        {
            myScore += scoreForStrike(frameIndex);
            frameIndex++;
        }
        else if (isSpare(frameIndex))
        {
            myScore += scoreForSpare(frameIndex);
            frameIndex+=2;
        }
        else
        {
            myScore += scoreForNoMark(frameIndex);
            frameIndex+=2;
        }
    }

    return myScore;
}

bool Game::isSpare(int frameIndex) {
    return rolls[frameIndex] + rolls[frameIndex+1] == 10;
}

bool Game::isStrike(int frameIndex) {
    return rolls[frameIndex] == 10;
}

int Game::scoreForStrike(int frameIndex) {
    return 10 + rolls[frameIndex+1] + rolls[frameIndex+2];
}

int Game::scoreForSpare(int frameIndex)
{
    return 10 + rolls[frameIndex+2];
}

int Game::scoreForNoMark(int frameIndex)
{
    return rolls[frameIndex] + rolls[frameIndex+1];
}