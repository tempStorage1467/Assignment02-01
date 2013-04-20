/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file is the starter project for the Random Writer problem. It
 *   reads a raw file, maps it, and uses it to generate a random string.
 */

#include <string>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "filelib.h"
#include "FileParser.h"
#include "FileParserTest.h"

using namespace std;

/*
 * Prompt the user for a file and read it into a stream.
 */
string getFile(ifstream& stream) {
    return promptUserForFile(stream, "Enter source text: ");
}

int getMarkovNumber() {
    return getInteger("Enter the Markov order [1-10]: ");
}

int main() {
    // Step 0: Run Tests
    FileParserTest test = FileParserTest();
    test.runTests();

    // Step 1: Prompt User for Valid File Name and Markov Number
    ifstream fileStream;
    string fileName = getFile(fileStream);
    
    const int MARKOV_NUMBER = getMarkovNumber();

    // Step 2: Parse File
    //   Take in a file stream and just read it as a long string
    //   Necessary to convert into a string so that a common input exists
    //   for parsing into a Map
    FileParser processToString = FileParser(fileStream);
    string sourceText = processToString.getSourceTextAsString();

    // Step 3: String -> Map Conversion
    // Take in:
    //   (i) raw string text
    //   (ii) Markov number, num chars in seed
    //   (iii) num next chars
    // read string char-by-char and assemble
    // Map<string seed, Vector<string next word>>
    
    
    // Step 4: Generate Text

    // [TODO: fill in the code]
    return 0;
}
