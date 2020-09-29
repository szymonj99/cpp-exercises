#include "StringFunctions.h"

int main()
{
	int myOtherString[10];
	convertToMyString("SAMPLE", myOtherString, sizeof(myOtherString) / sizeof(myOtherString[0]));
	outputMyString(myOtherString);

	int myFindString[10];
	convertToMyString("TEXT", myFindString, sizeof(myFindString) / sizeof(myFindString[0]));
	outputMyString(myFindString);
	
	int myConcatenatedString[20]{19};
	if (concatenate(myConcatenatedString, myOtherString, myFindString))
	{
		outputMyString(myConcatenatedString);
	}	

	int resultString[10]{ 9 };
	substring(resultString, myFindString, 1, 3);
	outputMyString(resultString);

	int trimString[10]{ 9, ' ', ' ', ' ', ' ', 'H' };
	trimMyString(trimString);

	std::cin.get();

	return 0;
}