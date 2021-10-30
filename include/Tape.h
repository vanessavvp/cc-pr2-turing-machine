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

#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <list>

#include "./Alphabet.h"

using namespace std;

#pragma once
class Tape {
  public:
    Tape(Alphabet alphabet);
    void setAlphabet(Alphabet alphabet);
    Alphabet getAlphabet() const;
    
  private:
    list<string> tape_;
    Alphabet alphabet_;
    list<string>::iterator head_;
};

#endif // !TAPE_H
