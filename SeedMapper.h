/*
 * File: SeedMapper.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file defines a class to read in a string,
 *   a Markov number, and a number of chars to predict.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef SEEDMAPPER_H_
#define SEEDMAPPER_H_

#include <iostream>
#include <string>
#include "map.h"
#include "vector.h"

using namespace std;

class SeedMapper {
 private:
    string rawInput;
    int markovNum;
    int numCharsPredict;
    Map<string, Vector<string> > seedMap;
    Map<string, int> seedFrequency;
    void processInputText();

 public:
    SeedMapper(const string& rawInput,
               const int& markovNum,
               const int& numCharsPredict);
    Map<string, Vector<string> > getSeedMap();
    string getMostCommonSeed();
};

#endif  // SEEDMAPPER_H_
