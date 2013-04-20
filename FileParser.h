/*
 * File: FileParser.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file defines a template for a class to parse a file into a long string.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <string>
#include <iostream>
#include <fstream>
#include "filelib.h"

using namespace std;

class FileParser {
 public:
    FileParser(ifstream& inFile);
    string getSourceTextAsString();
 private:
    ifstream* inputFile;
};

#endif  // FILEPARSER_H_
