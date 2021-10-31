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
#include <iterator>
#include <algorithm>

#include "./Alphabet.h"

using namespace std;

#pragma once
class Tape {
  public:
    Tape(Alphabet alphabet, string tapeContent, Symbol whiteSymbol);
    void setAlphabet(Alphabet alphabet);
    void setTape(string tapeContent);
    void setHead(Symbol newHeadSymbol);
    void moveLeft();
    void moveRight();
    Alphabet getAlphabet() const;
    list<Symbol>::iterator& getHead();
    void print();
    
  private:
    list<Symbol> tape_;
    Alphabet alphabet_;
    list<Symbol>::iterator head_;
    Symbol whiteSymbol_;
};

#endif // !TAPE_H
