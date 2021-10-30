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

Tape::Tape(Alphabet alphabet, string tapeContent) {
  alphabet_ = alphabet;
  setTape(tapeContent);
  head_ = tape_.begin();
  cout << "HEAD " << head_->getSymbol() << endl;
}


void Tape::setAlphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}


void Tape::setTape(string tapeContent) {
  for (int i = 0; i < tapeContent.size(); i++) {
    tape_.push_back(Symbol(string(1, tapeContent[i])));
  }
}


Alphabet Tape::getAlphabet() const {
  return alphabet_;
}