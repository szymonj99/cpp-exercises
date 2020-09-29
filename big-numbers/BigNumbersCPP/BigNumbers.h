#pragma once

#ifdef _WIN32
	#include <Windows.h> // Used for QueryPrecisionCounter on Windows
#endif
#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

// How many digits are there in the big int.
constexpr unsigned int MAX_NUM_OF_DIGITS = 1000;
// What's the max size of the array with 0th element storing the size.
constexpr unsigned int MAX_BIG_INT_SIZE = MAX_NUM_OF_DIGITS + 1;
// Largest possible number that can be stored in an element of array
constexpr unsigned int LARGEST_DIGIT = 9;

// Convert an integer to a big int, returning a pointer to the new big int array
int* ConvertIntToBigInt(const unsigned long long& INITIAL);

// Take in an initial integer that will be converted into a big int and input into the passed array
void PutValueIntoBigInt(const unsigned long long& INITIAL, int bigInt[]);

// Fill a big integer with random values
void FillBigInt(int bigInt[], const unsigned int numOfDigits);

// Add the second big integer to the first, resulting in a new value being set as the first big int.
// Will remove leading zeroes (if any) after returning.
void AddBigIntsInPlace(int first[], int second[]);

// Display a big integer to standard output (std::cout)
void DisplayBigInt(const int bigInt[]);

// Pad a big integer with leading zeroes.
void PadBigInt(int BigInt[], const unsigned int paddingAmount);

// Remove leading zeroes padding from a big integer.
void RemovePaddingBigInt(int bigInt[]);

struct Timer
{
#ifdef _WIN32
	LARGE_INTEGER start, end, frequency, numTicks;
#else
	std::chrono::time_point<std::chrono::high_resolution_clock> chrono_start, chrono_end;
	std::chrono::duration<float> chrono_duration;
#endif
	
	Timer();
	~Timer();
};
