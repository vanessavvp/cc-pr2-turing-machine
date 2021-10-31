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

Tape::Tape(Alphabet alphabet, string tapeContent, Symbol whiteSymbol) {
  alphabet_ = alphabet;
  setTape(tapeContent);
  head_ = tape_.begin();
  whiteSymbol_ = whiteSymbol;
}


void Tape::setAlphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}


void Tape::setTape(string tapeContent) {
  for (int i = 0; i < tapeContent.size(); i++) {
    tape_.push_back(Symbol(string(1, tapeContent[i])));
  }
}


void Tape::setHead(Symbol newHeadSymbol) {
  head_->setSymbol(newHeadSymbol.getSymbol());
}


Alphabet Tape::getAlphabet() const {
  return alphabet_;
}


list<Symbol>::iterator& Tape::getHead() {
  return head_;
}


void Tape::moveLeft() {
  list<Symbol>::iterator it = find(tape_.begin(), tape_.end(), *head_);
  advance(it, -1);
  head_ = it;
  if (it == tape_.begin()) {
    tape_.push_front(whiteSymbol_);
    advance(it, +1);
    head_ = it;
  }
}
    
    
void Tape::moveRight() {
  list<Symbol>::iterator it = find(tape_.begin(), tape_.end(), *head_);
  advance(it, 1);
  head_ = it;
  if (it == tape_.end()) {
    tape_.push_front(whiteSymbol_);
    advance(it, -1);
    head_ = it;
  }
}


void Tape::print() {
  for (auto symbol: tape_) {
    cout << symbol.getSymbol() << " ";
  }
  cout << endl;
}
