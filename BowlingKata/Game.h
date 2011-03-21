/* 
 * File:   Game.h
 * Author: Swalker
 *
 * Created on March 9, 2011, 10:28 AM
 */

#ifndef GAME_H
#define	GAME_H

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    void roll(int);
    int score();
private:
    int myScore;
    int rolls[21];
    int currentRoll;

    bool isSpare(int);
    bool isStrike(int);
    int scoreForStrike(int);
    int scoreForSpare(int);
    int scoreForNoMark(int);
};

#endif	/* GAME_H */

