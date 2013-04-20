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

bool SeedMapperTest::assertEquals(const Vector<string>& expected,
                                  const Vector<string>& actual) {
    if (expected.size() != actual.size()) {
        cout << "Test Failed; Vectors Unequal in Size" << endl;
        cout << "Expected size: " << expected.size() << "; Actual size: " <<
          actual.size() << endl;
        return false;
    }
    for (int i = 0; i < expected.size(); i++) {
        if (expected.get(i) != actual.get(i)) {
            cout << "Test Failed; Vectors Unequal" << endl;
            return false;
        }
    }
    return true;
}

bool SeedMapperTest::assertEquals(
                            const Map<string, Vector<string> >& expected,
                            const Map<string, Vector<string> >& actual) {

    if (expected.size() != actual.size()) {
        cout << "Test Fail -- Expected map size does not match "
             << "actual map size." << endl;
        return false;
    }
    foreach (string expectedKey in expected) {
        if (!actual.containsKey(expectedKey)) {
            cout << "Actual: " << endl;
            foreach (string key in actual) {
                cout << "Key:" << key << "; Values: ";
                for(int i = 0; i < actual.get(key).size(); i++) {
                    cout << actual.get(key).get(i) << ", ";
                }
                cout << endl;
            }
            return false;
        }
        if (!assertEquals(expected.get(expectedKey),
                          actual.get(expectedKey))) {
            cout << "Vectors for key '" << expectedKey << "' unequal" << endl;
            cout << "Expected Size: " << expected.get(expectedKey).size()
                 << "; Actual Size: " << actual.get(expectedKey).size() << endl;
            cout << "Actual Vector for key '" << expectedKey << "': ";
            for (int j = 0; j < actual.get(expectedKey).size(); j++) {
                cout << actual.get(expectedKey).get(j) << ", ";
            }
            cout << endl;
            return false;
        }
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
    
    Vector<string> map1A = expectedSeedMap1.get("as");
    map1A.add(" ");
    expectedSeedMap1.put("as", map1A);

    Vector<string> map1B = expectedSeedMap1.get("s ");
    map1B.add("g");
    expectedSeedMap1.put("s ", map1B);

    Vector<string> map1C = expectedSeedMap1.get(" g");
    map1C.add("r");
    expectedSeedMap1.put(" g", map1C);

    Vector<string> map1D = expectedSeedMap1.get("gr");
    map1D.add("e");
    expectedSeedMap1.put("gr", map1D);
    
    Vector<string> map1E = expectedSeedMap1.get("re");
    map1E.add("g");
    expectedSeedMap1.put("re", map1E);
    
    Vector<string> map1F = expectedSeedMap1.get("eg");
    map1F.add("o");
    expectedSeedMap1.put("eg", map1F);
    
    Vector<string> map1G = expectedSeedMap1.get("go");;
    map1G.add("r");
    expectedSeedMap1.put("go", map1G);
    
    Vector<string> map1H = expectedSeedMap1.get("or");;
    map1H.add("a");
    expectedSeedMap1.put("or", map1H);
    
    Vector<string> map1I = expectedSeedMap1.get("ra");;
    map1I.add("s");
    expectedSeedMap1.put("ra", map1I);
    
    Vector<string> map1J = expectedSeedMap1.get("as");
    map1J.add(" ");
    expectedSeedMap1.put("as", map1J);
    
    Vector<string> map1K = expectedSeedMap1.get("s ");
    map1K.add("S");
    expectedSeedMap1.put("s ", map1K);
    
    Vector<string> map1L = expectedSeedMap1.get(" S");
    map1L.add("a");
    expectedSeedMap1.put(" S", map1L);
    
    Vector<string> map1M = expectedSeedMap1.get("Sa");
    map1M.add("m");
    expectedSeedMap1.put("Sa", map1M);
    
    Vector<string> map1N = expectedSeedMap1.get("am");
    map1N.add("s");
    expectedSeedMap1.put("am", map1N);
    
    Vector<string> map1O = expectedSeedMap1.get("ms");
    map1O.add("a");
    expectedSeedMap1.put("ms", map1O);
    
    Vector<string> map1P = expectedSeedMap1.get("sa");
    map1P.add("s");
    expectedSeedMap1.put("sa", map1P);
    
    Vector<string> map1Q = expectedSeedMap1.get("as");;
    map1Q.add("i");
    expectedSeedMap1.put("as", map1Q);

    assertEquals(expectedSeedMap1, actualSeedMap1);

    // TEST 2
    string input2 = "as gre";
    SeedMapper mapper2 = SeedMapper(input2, 3, 2);
    Map<string, Vector<string> > actualSeedMap2 = mapper2.getSeedMap();
    Map<string, Vector<string> > expectedSeedMap2;

    Vector<string> map2A = expectedSeedMap2.get("as ");
    map2A.add("gr");
    expectedSeedMap2.put("as ", map2A);

    Vector<string> map2B = expectedSeedMap2.get("s g");
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
