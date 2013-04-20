/*
 * File: SeedMapper.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file implements a class to read in a string,
 *   a Markov number, and a number of chars to predict.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include "SeedMapper.h"

SeedMapper::SeedMapper(const string& input,
                       const int& markovNumber,
                       const int& numberCharsPredict) {
    rawInput = input;
    markovNum = markovNumber;
    numCharsPredict = numberCharsPredict;
}

Map<string, Vector<string> > SeedMapper::getSeedMap() {
    Vector<string> next;
    next.add("r");
    seedMap.put("governo", next);
    return seedMap;
}