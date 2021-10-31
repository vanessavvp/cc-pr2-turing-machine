/**
 * PROJECT HEADER
 * @file Main.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#include <iostream>

#include "../include/TuringMachine.h"

using namespace std;

int main(int argc, char* argv[]) {
  string inputFilename, inputString, menuRepeated;
  cout << "\n\tTuring Machine" << endl;
  try {
    cout << "\nPlease, enter the input file path of the Turing Machine definition: ";
    cin >> inputFilename;
    do {
      cout << "Enter the input string for the Turing Machine Tape: ";
      cin >> inputString;
      TuringMachine turingMachine(inputFilename);
      turingMachine.setTapes(inputString);
      turingMachine.checkString(inputString);

      cout << "\nDo you want to repeat the process [y/n]: ";
      cin >> menuRepeated;
    } while ((menuRepeated == "y") || (menuRepeated == "Y"));
  } catch (const string error) {
    cerr << error << endl;
  }
}