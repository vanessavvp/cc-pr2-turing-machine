/**
 * PROJECT HEADER
 * @file TuringMachine.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>

#include "./State.h"
#include "./Tape.h"

using namespace std;
#pragma once

class TuringMachine  {
  public:
    TuringMachine(string inputFilename, string inputString);
    bool isComment(string lineInfo);
    bool hasState(string lineInfo, vector<State>& states);
    void readFile(string inputFilename);
    void setAlphabet(string lineInfo);
    void setInitialState(string lineInfo, vector<State>& states);
    void setAcceptationStates(string lineInfo, vector<State>& states);
    void setTransition(string lineInfo, vector<State>& states);
    void setTapeAlphabet(string lineInfo);
    void setTapes(string tapeInput);
    void saveStates(string lineInfo, vector<State>& states);
    void checkString(string inputString);
    bool start(string inputString);

  private:
    set<State> states_;
    Alphabet alphabet_;
    Alphabet tapeAlphabet_;
    string currentState_;
    string initialState_;
    string whiteSymbol_;
    int numberOfTapes_;
    vector<Tape> tapes_;
};

#endif // !TURING_MACHINE_H