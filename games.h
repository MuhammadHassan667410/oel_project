// games.h
// This header file has the prototypes of all 6 game functions.
// The functions themselves are written in their own .cpp files.
// main.cpp includes this file so it can call every game.

#pragma once

// ----- EASY games -----
bool playWordSwapGame(int& triesUsed);      // word_swap.cpp
bool playMirroringGame(int& triesUsed);     // swap_game.cpp

// ----- MEDIUM games -----
bool playPatternGame(int& triesUsed);       // number_pattern.cpp
bool playAsciiGame(int& triesUsed);         // ASCII_game.cpp

// ----- HARD games -----
bool playReflectionGame(int& triesUsed);    // reverse_shift.cpp
bool playDetectiveGame();                   // murder.cpp (no tries in this one)
