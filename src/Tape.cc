/**
 * PROJECT HEADER
 * @file Tape.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#include "../include/Tape.h"

Tape::Tape(Alphabet alphabet, Symbol whiteSymbol) {
  alphabet_ = alphabet;
  whiteSymbol_ = whiteSymbol;
}


void Tape::setAlphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}


void Tape::setHead(list<Symbol>::iterator& head) {
  head_ = head;
}


void Tape::setTape(string tapeContent) {
  tape_.clear();
  for (int i = 0; i < tapeContent.size(); i++) {
    tape_.push_back(Symbol(string(1, tapeContent[i])));
  }
  head_ = tape_.begin();
}


void Tape::setHeadSymbol(Symbol newHeadSymbol) {
  (*head_).setSymbol(newHeadSymbol.getSymbol());
}


Alphabet Tape::getAlphabet() const {
  return alphabet_;
}


list<Symbol>::iterator& Tape::getHead() {
  return head_;
}


string Tape::getHeadSymbol() {
  return (*head_).getSymbol();
}


void Tape::moveLeft() {
  if (head_ == tape_.begin()) {
    tape_.push_front(whiteSymbol_);
    head_ = tape_.begin();
  } else {
    advance(head_, -1);
  }
}
    
    
void Tape::moveRight() {
  advance(head_, 1);
  if (head_ == tape_.end()) {
    tape_.push_back(whiteSymbol_);
    advance(head_, -1);
  } 
  
}


void Tape::print() {
  for (auto symbol: tape_) {
    cout << symbol.getSymbol() << " ";
  }
  cout << endl;
}


list<Symbol> Tape::getTape() {
  return tape_;
}
