#include <iostream>

#include "StringFunctions.h"

void convertToMyString(const char* nullString, int myString[], const int maxCharsInString)
{
	unsigned int currentPos = 0;
	while (nullString[currentPos] != 0 && currentPos < maxCharsInString)
	{
		myString[currentPos + 1] = nullString[currentPos];
		currentPos++;
	}
	myString[0] = currentPos;
}

void outputMyString(const int myString[])
{
	constexpr int ARRAY_STRING_LENGTH = 0;
	// Start at index 1, not 0, as 0th index is the size of the string.
	// So compare the loop index to the 0th index of the string to see how many characters to iterate over
	for (int i = 1; i <= myString[ARRAY_STRING_LENGTH]; i++)
	{
		std::cout << static_cast<char>(myString[i]);
	}
	std::cout << std::endl; // Clear the buffer.
}

int length(const int myString[])
{
	// Change to calculate the size properly rather than returning first element
	return myString[0];
}

void toUpperMyString(int myString[])
{
	// To convert lowerstring to upperstring, minus 32.
	constexpr unsigned int ASCII_CONVERSION = 32;
	for (int i = 1; i <= length(myString); i++)
	{
		myString[i] -= ASCII_CONVERSION;
	}
}

void toLowerMyString(int myString[])
{
	// To convert lowerstring to upperstring, add 32.
	constexpr unsigned int ASCII_CONVERSION = 32;
	for (int i = 1; i <= length(myString); i++)
	{
		myString[i] += ASCII_CONVERSION;
	}
}

int find(const int targetString[], const int myString[])
{
	const unsigned int TARGET_STRING_LENGTH = length(targetString);
	const unsigned int MY_STRING_LENGTH = length(myString);

	// Error checking
	// The target can't be longer than the original string
	if (TARGET_STRING_LENGTH > MY_STRING_LENGTH)
	{
		return 0;
	}

	// If the target is the same length as the string BUT the first character don't match
	// we can do an early return
	if ((TARGET_STRING_LENGTH == MY_STRING_LENGTH) && (targetString[1] != myString[1]))
	{
		return 0;
	}

	// Counter iterates over the whole of myString.
	for (unsigned int counter = 1; counter < MY_STRING_LENGTH; counter++)
	{
		// Tripwire algorithm
		bool found = false;

		// i is the index of the letter in the current word
		for (unsigned int i = 0; i < TARGET_STRING_LENGTH; i++)
		{
			if (myString[counter + i] == targetString[counter + i])
			{
				found = true;
			}
			else
			{
				found = false;
			}
		}
		if (found)
		{
			return counter - 1;
		}
	}

	return 0;
}

bool concatenate(int resultString[], int firstString[], int secondString[])
{
	const unsigned int RESULT_LENGTH = length(resultString);
	const unsigned int FIRST_LENGTH = length(firstString);
	const unsigned int SECOND_LENGTH = length(secondString);

	// Check if the result is large enough to hold the strings
	if (RESULT_LENGTH < FIRST_LENGTH + SECOND_LENGTH)
	{
		return false;
	}
	else
	{
		// concatenate first word
		for (unsigned int i = 1; i <= FIRST_LENGTH; i++)
		{
			resultString[i] = firstString[i];
		}
		// concatenate second word
		for (unsigned int j = 1; j <= SECOND_LENGTH; j++)
		{
			resultString[FIRST_LENGTH + j] = secondString[j];
		}
		return true;
	}
}

bool substring(int resultString[], const int firstString[], const int startPos, const int _length)
{
	// Check if the substring is of the right size
	if (startPos + _length > length(firstString))
	{
		return false;
	}
	else
	{
		for (unsigned int i = 0; i < _length; i++)
		{
			resultString[i + 1] = firstString[startPos + i];
		}
		return true;
	}
}

void trimMyString(int myString[])
{
	// Check how many spaces there are at the start.
	constexpr unsigned int SPACE = ' ';

	unsigned int leadingSpaces = 0;

	for (unsigned int i = 1; i <= length(myString); i++)
	{
		if (myString[i] != SPACE)
		{
			break;
		}
		else
		{
			leadingSpaces++;
		}
	}

	//for (unsigned int j = leadingSpaces + 1; )
}