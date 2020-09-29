#pragma once

#include "BigNumbers.h"

//#define LOGGING_ENABLED

int* ConvertIntToBigInt(const unsigned long long& INITIAL)
{
#ifdef LOGGING_ENABLED
	{
		std::cout << "Converting " << initial << "\n";
		Timer timer;
	}
#endif

	std::unique_ptr<int> BigInt[MAX_BIG_INT_SIZE];

	unsigned long long temp = INITIAL;
	unsigned int digit = 1;

	while (temp != 0)
	{
		BigInt->get()[digit] = temp % 10;
		temp /= 10;
		digit++;
	}
	BigInt->get()[0] = digit - 1;

	return BigInt->get();
}

void FillBigInt(int bigInt[], const unsigned int numOfDigits)
{
#ifdef LOGGING_ENABLED
	{
		if (num_of_digits > MAX_NUM_OF_DIGITS)
		{
			std::cout << "Trying to fill big int with too many digits: " << num_of_digits << "\n";
		}
		else
		{
			std::cout << "Filling a big int with X digits: " << num_of_digits << "\n";
		}
		Timer timer;
	}
#endif

	// Check if the passed argument is not bigger than max digits
	if (numOfDigits > MAX_NUM_OF_DIGITS)
	{
		for (unsigned int i = 1; i <= MAX_NUM_OF_DIGITS; i++)
		{
			bigInt[i] = rand() % LARGEST_DIGIT;
		}
		bigInt[0] = MAX_NUM_OF_DIGITS;
	}
	else
	{
		for (unsigned int i = 1; i <= numOfDigits; i++)
		{
			bigInt[i] = rand() % LARGEST_DIGIT;
		}
		bigInt[0] = numOfDigits;
	}
	// Ensure the last digit is not 0
	while (bigInt[bigInt[0]] == 0)
	{
		bigInt[bigInt[0]] = rand() % LARGEST_DIGIT;
	}
}

void PadBigInt(int BigInt[], const unsigned int paddingAmount)
{
#ifdef LOGGING_ENABLED
	{
		std::cout << "Padding a big integer with X leading zeroes: " << padding_amount << "\n";
		Timer timer;
	}
#endif

	for (unsigned int i = BigInt[0] + 1; i <= BigInt[0] + paddingAmount; i++)
	{
		BigInt[i] = 0;
	}
	BigInt[0] += paddingAmount;
}

void RemovePaddingBigInt(int bigInt[])
{
#ifdef LOGGING_ENABLED
	{
		std::cout << "Removing padding from big int\n";
		Timer timer;
	}
#endif

	unsigned int i = bigInt[0];
	unsigned int zeroes_to_remove = 0;

	while (i > 0)
	{
		if (bigInt[i] == 0)
		{
			zeroes_to_remove++;
			i--;
		}
		else
		{
			bigInt[0] -= zeroes_to_remove;
			break;
		}
	}
}

void AddBigIntsInPlace(int first[], int second[])
{
#ifdef LOGGING_ENABLED
	{
		std::cout << "Adding in place two big integers with X and Y digits: " << First[0] << " " << Second[0] << "\n";
		Timer timer;
	}
#endif

	// Check if big ints are not the same size so that padding can be added
	if (first[0] > second[0])
	{		
		const unsigned int size_difference = first[0] - second[0];
		PadBigInt(second, size_difference);
	}
	else if (first[0] < second[0])
	{
		const unsigned int size_difference = second[0] - first[0];
		PadBigInt(first, size_difference);
	}

	unsigned int carry = 0;
	unsigned int limit = first[0];
	for (unsigned int i = 1; i <= limit; i++)
	{
		first[i] += second[i] + carry;
		carry = 0;
		if (first[i] > LARGEST_DIGIT)
		{
			carry = 1;
			first[i] = first[i] - (LARGEST_DIGIT + 1);
		}
	}
	if (carry == 1)
	{
		first[limit + 1] = 1;
		first[0] = limit + 1;
	}

	RemovePaddingBigInt(first);
	RemovePaddingBigInt(second);
}

void DisplayBigInt(const int bigInt[])
{
#ifdef LOGGING_ENABLED
	{
		std::cout << "Displaying a big int that has X digits: " << bigInt[0] << " \n";
		Timer timer;
	}
#endif

	// Append all digits to a string then print using a single string only.
	// When compared to doing std::cout for each digit, it's about 10x faster.
	std::string output;
	for (unsigned int i = bigInt[0]; i >= 1; i--)
	{
		output.append(std::to_string(bigInt[i]));
	}
	std::cout << output << "\n";
}

void PutValueIntoBigInt(const unsigned long long& INITIAL, int bigInt[])
{

}

//int* MultiplyBigInts(int first[], int second[])
//{
//#ifdef LOGGING_ENABLED
//	{
//		std::cout << "Multiplying big ints with X and Y digits: " << first[0] << " " << second[0] << "\n";
//		Timer timer;
//	}
//#endif
//
//
//
//}

// Use this to begin measuring time.
Timer::Timer()
{
#ifdef _WIN32
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
#else
		chrono_start = std::chrono::high_resolution_clock::now();
#endif
}

// When the Timer object is destroyed, calculate time taken.
Timer::~Timer()
{
#ifdef _WIN32
	QueryPerformanceCounter(&end);
	numTicks.QuadPart = end.QuadPart - start.QuadPart;
	std::cout << "Time: " << static_cast<double>(numTicks.QuadPart) / static_cast<double>(frequency.QuadPart) << " seconds.\n";
#else
	chrono_end = std::chrono::high_resolution_clock::now();
	chrono_duration = chrono_end - chrono_start;

	// Get duration value in milliseconds
	constexpr float MILLISECONDS_MULTIPLIER = 1000.0f;
	std::cout << "Timer took " << chrono_duration.count() * MILLISECONDS_MULTIPLIER << " ms.\n";
#endif
}