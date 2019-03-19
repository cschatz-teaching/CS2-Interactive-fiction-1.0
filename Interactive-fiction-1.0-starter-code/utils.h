/*

 ABOUT THIS FILE
 ---------------

 This file provides a handful of potentially useful utility functions.
 Please read the function prototypes and descriptions below.

*/

#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string ConvertToLowercase(string s);
// Returns a version of the given string with all
// characters converted to lowercase.

string ConvertToString(int iNum);
// Converts the given integer to a string.

string ConvertToString(double dNum);
// Converts the given double to a string.

vector<string> DivideLineIntoWords(string line);
// Returns a vector whose components are the individual
// words from the given string

string WrappedString(string text, int maxWidth);
// Returns a string that is equivalent to the given string,
// but with newlines added so it is divided into lines within the
// given maximum width.

void UnAbbreviate(string& word);
// If the given string is a known abbrevation (e.g., "i" for "inventory"),
// this function *changes* that string to the full-word equivalent.

#endif
