/**
 * PROJECT HEADER
 * @file Symbol.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

using namespace std;
#pragma once

class Symbol {
  public:
    Symbol() {};
    ~Symbol() {};
    Symbol(string symbol);
    string getSymbol();
    void setSymbol(string symbol);
    void print();
    bool operator<(Symbol const& other) const;
    bool operator==(Symbol const& other) const;
    
  private:
    string symbol_;
};

#endif // !SYMBOL_H