/**
 * PROJECT HEADER
 * @file State.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º2
 * Purpose: Implementing a Turing Machine
 */

#include "../include/State.h"

State::State() {
  identifier_ = "0";
  isAcceptation_ = false;
  isInitial_ = false;
}


State::State(string identifier) {
  identifier_ = identifier;
  isAcceptation_ = false;
  isInitial_ = false;
}


State::State(string identifier, bool isAcceptation, bool isInitial) {
  identifier_ = identifier;
  isAcceptation_ = isAcceptation;
  isInitial_ = isInitial;
}


void State::setIdentifier(string identifier) {
  identifier_ = identifier;
}


string State::getIdentifier() const {
  return identifier_;
}


vector<Transition> State::getTransitions() const {
  return transitions_;
}


bool State::isAcceptation() const {
  return isAcceptation_;
}


bool State::isInitial() const {
  return isInitial_;
}


void State::setAcceptation(bool isAcceptation) {
  isAcceptation_ = isAcceptation;
}


void State::setInitial(bool isInitial) {
  isInitial_ = isInitial;
}


void State::setTransitions(vector<Transition>& transitions) {
  transitions_ = transitions;
}


void State::addTransition(Transition& transition) {
  transitions_.push_back(transition);
}


bool State::operator<(State const& other) const {
  if (this->identifier_ < other.identifier_ ) { 
    return true;
  }
  return false;
}


bool State::operator==(State const& other) const {
  if (other.identifier_ == this->identifier_) {
    return true;
  }
  return false;
}
