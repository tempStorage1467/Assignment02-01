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
                             const int& markovNumber,
                             const int& numCharsToPredict,
                             const Map<string, Vector<string> >& inputSeedMap) {
    seed = inputSeed;
    numCharsPredicted = numCharsToPredict;
    markovNum = markovNumber;
    seedMap = &inputSeedMap;
}

string TextGenerator::getRandomText(unsigned int numCharsToGenerate) {
    string outputText = seed;
    string currentSeed = seed;
    Vector<string> possibleNextChars;
    int nextCharsIndexNum = 0;

    while (outputText.length() + numCharsPredicted <= numCharsToGenerate) {
        if (!seedMap->containsKey(currentSeed)) {
            return outputText;
        }
        
        possibleNextChars = seedMap->get(currentSeed);
        nextCharsIndexNum = randomInteger(0, possibleNextChars.size() - 1);
        outputText += possibleNextChars.get(nextCharsIndexNum);
        currentSeed = outputText.substr(outputText.length() - markovNum);
    }

    return outputText;
}
