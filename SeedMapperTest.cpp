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

    // This is only a rough test. It does not compare element by element,
    //   so it may miss some errors.
    if (expected.size() != actual.size()) {
        cout << "Test Fail -- Expected does not match actual. Actual: " << endl;
        foreach (string key in actual) {
            cout << "Key:" << key << "; Value: ";
            for(int i = 0; i < actual.get(key).size(); i++) {
                cout << actual.get(key).get(i) << ", ";
            }
            cout << endl;
        }
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
    testGetSeedMap();
    testGetMostCommonSeed();
}

void SeedMapperTest::testGetSeedMap() {
    // TEST 1
    string input1 = "as gregoras Samsasi";
    SeedMapper mapper1 = SeedMapper(input1, 2, 1);
    Map<string, Vector<string> > actualSeedMap1 = mapper1.getSeedMap();
    Map<string, Vector<string> > expectedSeedMap1;
    
    Vector<string> map1A;
    map1A.add(" ");
    expectedSeedMap1.put("as", map1A);
    Vector<string> map1B;
    map1B.add("g");
    expectedSeedMap1.put("s ", map1B);
    Vector<string> map1C;
    map1C.add("r");
    expectedSeedMap1.put(" g", map1C);
    Vector<string> map1D;
    map1D.add("e");
    expectedSeedMap1.put("gr", map1D);
    Vector<string> map1E;
    map1E.add("g");
    expectedSeedMap1.put("re", map1E);
    Vector<string> map1F;
    map1F.add("o");
    expectedSeedMap1.put("eg", map1F);
    Vector<string> map1G;
    map1G.add("r");
    expectedSeedMap1.put("go", map1G);
    Vector<string> map1H;
    map1H.add("a");
    expectedSeedMap1.put("or", map1H);
    Vector<string> map1I;
    map1I.add("s");
    expectedSeedMap1.put("ra", map1I);
    Vector<string> map1J;
    map1J.add(" ");
    expectedSeedMap1.put("as", map1J);
    Vector<string> map1K;
    map1K.add("S");
    expectedSeedMap1.put("s ", map1K);
    Vector<string> map1L;
    map1L.add("a");
    expectedSeedMap1.put(" S", map1L);
    Vector<string> map1M;
    map1M.add("m");
    expectedSeedMap1.put("Sa", map1M);
    Vector<string> map1N;
    map1N.add("s");
    expectedSeedMap1.put("am", map1N);
    Vector<string> map1O;
    map1O.add("a");
    expectedSeedMap1.put("ms", map1O);
    Vector<string> map1P;
    map1P.add("s");
    expectedSeedMap1.put("sa", map1P);
    Vector<string> map1Q;
    map1Q.add("i");
    expectedSeedMap1.put("as", map1Q);

    assertEquals(expectedSeedMap1, actualSeedMap1);

    // TEST 2
    string input2 = "as gre";
    SeedMapper mapper2 = SeedMapper(input2, 3, 2);
    Map<string, Vector<string> > actualSeedMap2 = mapper2.getSeedMap();
    Map<string, Vector<string> > expectedSeedMap2;

    Vector<string> map2A;
    map2A.add("gr");
    expectedSeedMap2.put("as ", map2A);
    Vector<string> map2B;
    map2B.add("re");
    expectedSeedMap2.put("s g", map2B);

    assertEquals(expectedSeedMap2, actualSeedMap2);
}

void SeedMapperTest::testGetMostCommonSeed() {
    // TEST 1
    string input1 = "as gregoras Samsasi";
    SeedMapper mapper1 = SeedMapper(input1, 2, 1);
    string mostCommonSeed1 = mapper1.getMostCommonSeed();
    assertEquals("as", mostCommonSeed1);

    // TEST 2
    string input2 = "As Gregor Samsa awoke one morning from uneasy dreams he "
      "found himself transformed in his bed into a gigantic insect.";
    SeedMapper mapper2 = SeedMapper(input2, 2, 1);
    string mostCommonSeed2 = mapper2.getMostCommonSeed();
    assertEquals("in", mostCommonSeed2);
}
