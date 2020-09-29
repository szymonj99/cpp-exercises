#pragma once

#include <iostream>

// Convert from standard null-terminated string representation to length-first format.
// nullString is a null-terminated string (a standard C string)
// myString is a string using our length + body representation
// maxCharsInString is the maximum number of characters myString can hold.
void convertToMyString(const char* nullString, int myString[], const int maxCharsInString);

// Display a string in our format to standard output (i.e. using cout)
void outputMyString(const int myString[]);

// Return the number of characters in the string
int length(const int myString[]);

// Convert any lower case characters to upper case
// e.g. "Cat1" would be converted to "CAT1"
void toUpperMyString(int myString[]);

// Convert any upper case characters to lower case
// e.g. "Cat1" would be converted to "cat1"
void toLowerMyString(int myString[]);

// Return the start position of the targetString in myString if present
// Return 0 if targetString is not present in myString
int find(const int targetString[], const int myString[]);

// Combine the first and second strings into resultString if they fit
// Return true if successful; return false if the strings don't fit
// e.g. "cat" and "fish" becomes "catfish"
bool concatenate(int resultString[], int firstString[], int secondString[]);

// Put the substring of given length starting at startPos into resultString
// Return true if successful; return false if the parameters are invalid
// e.g. the substring of "fred" starting at position 2 of length 3 is "red"
bool substring(int resultString[], const int firstString[], const int startPos, const int length);

// Remove any leading and trailing spaces
// e.g " fred " would be converted to "fred"
void trimMyString(int myString[]);