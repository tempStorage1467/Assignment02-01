/*
 * File: TextGenerator.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file implements a class that generates random text based upon a seed
 *   and a seed map.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include "TextGenerator.h"

TextGenerator::TextGenerator(const string& inputSeed,
                             const Map<string, Vector<string> >& inputSeedMap) {
    seed = inputSeed;
    seedMap = inputSeedMap;
}

string TextGenerator::getRandomText(unsigned int numChars) {
    
}