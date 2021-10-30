/**
 * PROJECT HEADER
 * @file Transition.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#include "../include/Transition.h"

Transition::Transition(string currentState, vector<Symbol> readingSymbols, string nextState, vector<Symbol> writingSymbols, vector<string> movements) {
  currentState_ = currentState;
  readingSymbols_ = readingSymbols;
  nextState_ = nextState;
  writingSymbols_ = writingSymbols;
  movements_ = movements;
}


void Transition::setCurrentState(string currentState) {
  currentState_ = currentState;
}


void Transition::setReadingSymbols(vector<Symbol> readingSymbols) {
  readingSymbols_ = readingSymbols;
}


void Transition::setNextState(string nextState) {
  nextState_ = nextState;
}


void Transition::setWritingSymbols(vector<Symbol> writingSymbols) {
  writingSymbols_ = writingSymbols;
}


void Transition::setMovements(vector<string> movements) {
  movements_ = movements;
}


string Transition::getCurrentState() {
  return currentState_;
}


vector<Symbol> Transition::getReadingSymbols() {
  return readingSymbols_;
}


string Transition::getNextState() {
  return nextState_;
}


vector<Symbol> Transition::getWritingSymbols() {
  return writingSymbols_;
}


void Transition::printTransition() {
  cout << "\n" << currentState_ << " ";
  for (auto symbol : readingSymbols_) {
    cout << symbol.getSymbol() << " ";
  }
  cout << nextState_ << " ";
  for (auto symbol : writingSymbols_) {
    cout << symbol.getSymbol() << " ";
  }
  cout << " ";
  for (auto movement : movements_) {
    cout << movement << " ";
  }
  cout << "\n";
}


bool Transition::isPossibleToTransit(Symbol headTape, int index) {
  return (headTape == readingSymbols_[index]);
}


vector<string> Transition::getMovements() {
  return movements_;
}

