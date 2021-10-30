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


bool TuringMachine::hasState(string lineInfo, vector<State>& states) {
  for (auto& state : states) {
    if (state.getIdentifier() == lineInfo) {
      return true;
    }
  }
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


void TuringMachine::setInitialState(string lineInfo, vector<State>& states) {
  string error;
  if (hasState(lineInfo, states)) {
    for (auto &state : states) {
      if (state.getIdentifier() == lineInfo) {
        state.setInitial(true);
        currentState_ = lineInfo;
      }
    }
  } else {
    error = "The readed state is not part of the Turing Machine states\n";
    throw error;
  }
}


void TuringMachine::setAcceptationStates(string lineInfo, vector<State>& states) {
  string error;
  string stateIdentifier;
  stringstream token(lineInfo);
  while (getline(token, stateIdentifier, ' ')) {
    if (hasState(stateIdentifier, states)) {
      for (auto &state : states) {
        if (state.getIdentifier() == lineInfo) {
          state.setAcceptation(true);
        }
      }
    } else {
      error = "The readed state is not part of the Turing Machine states\n";
      throw error;
    }
  }
}


void TuringMachine::setTransition(string lineInfo, vector<State>& states) {
  string word, error;
  Transition transition;
  stringstream ss(lineInfo);

  // Current state
  ss >> word;
  for (auto state: states) {
    if (word == state.getIdentifier()) {
      transition.setCurrentState(state.getIdentifier());
    }
  }

  // Reading symbols
  vector<Symbol> readingSymbols;
  for (int i = 0; i < numberOfTapes_; i++) {
    ss >> word;
    Symbol readingSymbol(word);
    readingSymbols.push_back(readingSymbol);
  }
  transition.setReadingSymbols(readingSymbols);

  // Next state
  ss >> word;
  for (auto state: states) {
    if (word == state.getIdentifier()) {
      transition.setNextState(state.getIdentifier());
    }
  }

  // Writing symbols
  vector<Symbol> writingSymbols;
  for (int i = 0; i < numberOfTapes_; i++) {
    ss >> word;
    Symbol writingSymbol(word);
    writingSymbols.push_back(writingSymbol);
  }
  transition.setWritingSymbols(writingSymbols);

  // Movements
  vector<string> movements;
  for (int i = 0; i < numberOfTapes_; i++) {
    ss >> word;
    movements.push_back(word);
  }
  transition.setMovements(movements);

  // Including transitions to a state
  auto it = find(states.begin(), states.end(), State(transition.getCurrentState()));
  if (it != states.end()) {
    (*it).addTransition(transition);
  }
  //transition.printTransition();
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

    // Initial State
    getline(file, lineInfo);
    setInitialState(lineInfo, states);

    // White symbol
    getline(file, lineInfo);
    whiteSymbol_ = lineInfo;

    // Acceptation states
    getline(file, lineInfo);
    setAcceptationStates(lineInfo, states);

    // Number of tapes
    getline(file, lineInfo);
    numberOfTapes_ = stoi(lineInfo);
    cout << "Numero de cintas " << numberOfTapes_ << endl;

    // Transitions
    while(getline(file, lineInfo)) {
      setTransition(lineInfo, states);
    }
  }
}


void TuringMachine::setTapes(string tapeInput) {
  for (int i = 0; i < numberOfTapes_; i++) {
    Tape tape(tapeAlphabet_, tapeInput);
    tapes_.push_back(tape);
  }
}

void TuringMachine::start() {

}