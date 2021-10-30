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

Tape::Tape(Alphabet alphabet) {
  alphabet_ = alphabet;
}


void Tape::setAlphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}


Alphabet Tape::getAlphabet() const {
  return alphabet_;
}