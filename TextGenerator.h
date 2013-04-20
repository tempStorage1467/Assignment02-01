/*
 * File: TextGenerator.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file defines a class that generates random text based upon a seed
 *   and a seed map.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef __Random_Writer__TextGenerator__
#define __Random_Writer__TextGenerator__

#include <iostream>
#include <string>
#include "map.h"
#include "vector.h"
#include "random.h"

class TextGenerator {
 private:
    string seed;
    int markovNum;
    int numCharsPredicted;
    const Map<string, Vector<string> >* seedMap;
 public:
    TextGenerator(const string& inputSeed,
                  const int& markovNumber,
                  const int& numCharsToPredict,
                  const Map<string, Vector<string> >& inputSeedMap);
    string getRandomText(unsigned int numCharsToGenerate);
};

#endif /* defined(__Random_Writer__TextGenerator__) */
