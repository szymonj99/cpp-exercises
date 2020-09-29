#pragma once

#include "BigNumbers.h"

int main()
{
	// Create two big ints
	int BigIntA[MAX_BIG_INT_SIZE];
	int BigIntB[MAX_BIG_INT_SIZE];
		
	// Pseudo-Random seed
	srand(static_cast<unsigned int>(time(0)));

	FillBigInt(BigIntA, 10);
	FillBigInt(BigIntB, 7);

	DisplayBigInt(BigIntA);
	DisplayBigInt(BigIntB);

	//std::unique_ptr<int> BigIntC = static_cast<std::unique_ptr<int>>(ConvertIntToBigInt(356778435));
	//DisplayBigInt(BigIntC.get());

	AddBigIntsInPlace(BigIntA, BigIntB);

	DisplayBigInt(BigIntA);
	DisplayBigInt(BigIntB);

	std::cin.get();
	return 0;
}