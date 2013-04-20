/*
 * File: FileParser.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file implements a class to parse a file into a string.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include "FileParser.h"
using namespace std;

FileParser::FileParser(ifstream& inFile) {
    inputFile = &inFile;
}

string FileParser::getSourceTextAsString() {
    string rawText = "";
    string line;
    string extra;
    while (!inputFile->eof()) {
        getline(*inputFile, line);
        extra = ((line.substr(line.size() - 1) != " ") ? " " : "");
        rawText += line + extra;
    }
    return rawText;
}
