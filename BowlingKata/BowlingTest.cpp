
#include "Game.h"
#include <CppUTest/TestHarness.h>

TEST_GROUP(BowlingGameTest)
{
    Game g;
};

void rollMany(int rolls, int pins, Game &g)
{
    for (int i = 0; i < rolls; i++)
        g.roll(pins);
}

void rollSpare(Game &g)
{
    g.roll(5);
    g.roll(5);
}

TEST(BowlingGameTest, Test)
{
    CHECK_EQUAL(0,0);
}

TEST(BowlingGameTest, CheckGutterGame)
{
    rollMany(20, 0, g);
    CHECK_EQUAL(0,g.score());
}

TEST(BowlingGameTest, CheckAllOnesGame)
{
    rollMany(20,1,g);
    CHECK_EQUAL(20,g.score());
}

TEST(BowlingGameTest, CheckSpare)
{
    rollSpare(g);
    g.roll(3);
    CHECK_EQUAL(16, g.score());
}

TEST(BowlingGameTest, CheckStrike)
{
    g.roll(10);
    g.roll(5);
    g.roll(3);
    g.roll(7);
    CHECK_EQUAL(33, g.score());
}

TEST(BowlingGameTest, CheckMixedMarks)
{
    g.roll(10);
    rollSpare(g);
    g.roll(3);
    g.roll(5);
    CHECK_EQUAL(41, g.score());
}

TEST(BowlingGameTest, CheckPerfectGame)
{
    rollMany(12,10,g);
    CHECK_EQUAL(300, g.score());
}