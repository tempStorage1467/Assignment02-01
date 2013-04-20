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

#include <string>
#include "SeedMapper.h"

using namespace std;

SeedMapper::SeedMapper(const string& input,
                       const int& markovNumber,
                       const int& numberCharsPredict) {
    rawInput = input;
    markovNum = markovNumber;
    numCharsPredict = numberCharsPredict;
    processInputText();
}

Map<string, Vector<string> > SeedMapper::getSeedMap() {
    return seedMap;
}

string SeedMapper::getMostCommonSeed() {
    string mostCommonSeed = "";
    int mostCommonSeedCount = -1;
    foreach (string seed in seedFrequency) {
        if (seedFrequency[seed] > mostCommonSeedCount) {
            mostCommonSeedCount = seedFrequency[seed];
            mostCommonSeed = seed;
        }
    }
    return mostCommonSeed;
}

void SeedMapper::processInputText() {
    string seed = "";
    string nextChars = "";

    // Determine how many times to iterate over raw input string.
    //   Need to shorten iterations based upon markovNum as we must
    //   ensure that there are enough chars left in the seed for the string
    //   Need to shorten iteratiosn based upon numCharsPredict as we must
    //   ensure that there are enough chars to the right of the current
    //   position to predict (i.e., if we want to predict 2 chars, we need
    //   to ensure that there are two chars left).
    int lenTo = rawInput.length() - markovNum - numCharsPredict + 1;
    for (int i = 0; i < lenTo; i++) {
        seed = rawInput.substr(i, markovNum);
        nextChars = rawInput.substr((i + markovNum), numCharsPredict);
        
        // update seedMap, which contains a map from the seed
        //   to a vector of strings of length numCharsPredict that
        //   follow the seed
        Vector<string> next = seedMap.get(seed);
        next += nextChars;
        seedMap.put(seed, next);

        // update seedFrequency, which contains a map between the seed
        //   and the number of times that seed occurs.
        //   Seems very inefficient to iterate over a bunch of vectors later.
        seedFrequency[seed] += 1;
    }
}
