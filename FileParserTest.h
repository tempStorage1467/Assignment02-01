/*
 * File: FileParserTest.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file defines a class to test a file parser.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef FILEPARSERTEST_H_
#define FILEPARSERTEST_H_

#include <iostream>
#include <string>
#include "simpio.h"
#include "filelib.h"
#include "FileParser.h"

using namespace std;

class FileParserTest {
 private:
    bool assertEquals(const string& expected, const string& actual);
 public:
    void runTests();
};

#endif  // FILEPARSERTEST_H_
