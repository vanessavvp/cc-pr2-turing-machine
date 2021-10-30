/**
 * PROJECT HEADER
 * @file Transition.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <vector>

#include "./Symbol.h"
#include "./State.h"

using namespace std;
#pragma once

class State;
class Transition {
  public:
    Transition() {};
    Transition(string currentState, vector<Symbol> readingSymbols, string nextState, vector<Symbol> writingSymbols, vector<string> movements);
    void setCurrentState(string currentState);
    void setReadingSymbols(vector<Symbol> readingSymbols);
    void setNextState(string nextState);
    void setWritingSymbols(vector<Symbol> symbolsToIntroduce);
    string getCurrentState();
    vector<Symbol> getReadingSymbols();
    string getNextState();
    vector<Symbol> getWritingSymbols();
    void printTransition();
    //bool isPossibleToTransit(string symbolToRead, Symbol topStackSymbol);

  private:
    string currentState_;
    vector<Symbol> readingSymbols_;
    string nextState_;
    vector<Symbol> writingSymbols_;
    vector<string> movements_;
};

#endif // !TRANSITION_H
