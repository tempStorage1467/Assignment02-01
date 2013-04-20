/*
 * File: SeedMapperTest.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 2 - Random Writer
 * This file defines a class that tests a the SeedMapper.
 *
 * This file lightly linted using:
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef SEEDMAPPERTEST_H_
#define SEEDMAPPERTEST_H_

#include <iostream>
#include "map.h"
#include "vector.h"
#include "simpio.h"
#include "SeedMapper.h"

class SeedMapperTest {
 private:
    bool assertEquals(const Map<string, Vector<string> >& expected,
                      const Map<string, Vector<string> >& actual);
    bool assertEquals(const Vector<string>& expected,
                      const Vector<string>& actual);
    bool assertEquals(const string& expected,
                      const string& actual);
    void testGetSeedMap();
    void testGetMostCommonSeed();

 public:
    void runTests();
};

#endif  // SEEDMAPPERTEST_H_
