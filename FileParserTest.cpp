/*
 * File: FileParserTest.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file implements a class to run tests on a file parser.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include "FileParserTest.h"

void FileParserTest::runTests() {
    // Test 1
    ifstream fileStream1;
    openFile(fileStream1, "Simple1.txt");
    FileParser parser1 = FileParser(fileStream1);
    string actual1 = parser1.getSourceTextAsString();
    assertEquals("This is a simple test. ", actual1);

    // Test 2
    ifstream fileStream2;
    openFile(fileStream2, "Simple2.txt");
    FileParser parser2 = FileParser(fileStream2);
    string actual2 = parser2.getSourceTextAsString();
    assertEquals("This is a simple test. A new line here. ", actual2);
}

bool FileParserTest::assertEquals(const string& expected,
                                  const string& actual) {
    if (expected == actual) {
        return true;
    } else {
        cout << "Test Fail -- Expected: " << expected << "; Actual: " <<
            actual << endl;
        return false;
    }
}
