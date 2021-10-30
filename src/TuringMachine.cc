/**
 * PROJECT HEADER
 * @file TuringMachine.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#include "../include/TuringMachine.h"

TuringMachine::TuringMachine(string inputFilename) {
  readFile(inputFilename);
}


bool TuringMachine::isComment(string lineInfo) {
  if (lineInfo.front() == '#') return true;
  return false;
}


void TuringMachine::saveStates(string lineInfo, vector<State>& states) {
  string stateIdentifier;
  stringstream token(lineInfo);
  while (getline(token, stateIdentifier, ' ')) {
    State state(stateIdentifier, false, false);
    states.push_back(state);
  }
}


void TuringMachine::setAlphabet(string lineInfo) {
  string symbol;
  stringstream token(lineInfo);
  set<Symbol> symbols;
  while (getline(token, symbol, ' ')) {
    Symbol inputSymbol(symbol);
    symbols.insert(inputSymbol);
  }
  alphabet_.setAlphabet(symbols);
}


void TuringMachine::setTapeAlphabet(string lineInfo) {
  string symbol;
  stringstream token(lineInfo);
  set<Symbol> symbols;
  while (getline(token, symbol, ' ')) {
    Symbol tapeSymbol(symbol);
    symbols.insert(tapeSymbol);
  }
  tapeAlphabet_.setAlphabet(symbols);
}


void TuringMachine::readFile(string inputFilename) {
  ifstream file(inputFilename);
  string lineInfo;
  string error;

  if (file.fail()) {
    error = "\nERROR: The inputfile  " + inputFilename + " failed!\n";
    throw error;
  } else {
    // cout << "\tThe inputfile " << inputFilename << " was successfully readed!\n";

    // Comments control
    getline(file, lineInfo);
    while(isComment(lineInfo)) {
      getline(file, lineInfo);
    }

    // Auxiliar set of states
    vector<State> states;
    saveStates(lineInfo, states);

    // Input alphabet
    getline(file, lineInfo);
    setAlphabet(lineInfo);

    // Tape alphabet
    getline(file, lineInfo);
    setTapeAlphabet(lineInfo);
    cout << "Alfabeto cinta: ";
    for (auto symbol: tapeAlphabet_.getAlphabet()) {
    cout << symbol.getSymbol() << " ";
    }
  
  }
}


void TuringMachine::start() {

}