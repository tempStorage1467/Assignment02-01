/*
 * File: SeedMapperTest.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file implements a class that tests a the SeedMapper.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include "SeedMapperTest.h"

bool SeedMapperTest::assertEquals(
                            const Map<string, Vector<string> >& expected,
                            const Map<string, Vector<string> >& actual) {
    if (expected.size() != actual.size()) {
        cout << "Test Fail -- Expected does not match actual" << endl;
        return false;
    }
    return true;
}

bool SeedMapperTest::assertEquals(const string& expected,
                                  const string& actual) {
    if (expected != actual) {
        cout << "Test Fail -- Expected: " << expected << " -- Actual: " <<
           actual << endl;
        return false;
    }
    return true;
}

void SeedMapperTest::runTests() {
    //testGetSeedMap();
    testGetMostCommonSeed();
}

void SeedMapperTest::testGetSeedMap() {
    string input = "As Gregor Samsa awoke one morning from uneasy dreams he "
    "found himself transformed in his bed into a gigantic insect.";
    SeedMapper mapper = SeedMapper(input, 2, 1);
    Map<string, Vector<string> > actualSeedMap = mapper.getSeedMap();

    Map<string, Vector<string> > expectedSeedMap;
    
}

void SeedMapperTest::testGetMostCommonSeed() {
    string input1 = "as gregoras Samsasi";
    SeedMapper mapper1 = SeedMapper(input1, 2, 1);
    string mostCommonSeed1 = mapper1.getMostCommonSeed();
    assertEquals("as", mostCommonSeed1);

    string input2 = "As Gregor Samsa awoke one morning from uneasy dreams he "
      "found himself transformed in his bed into a gigantic insect.";
    SeedMapper mapper2 = SeedMapper(input2, 2, 1);
    string mostCommonSeed2 = mapper2.getMostCommonSeed();
    assertEquals("in", mostCommonSeed2);
}
