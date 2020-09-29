#include <iostream>
#include <string>

int main()
{
	// Total amount of numbers to iterate over
	constexpr unsigned int TOTAL = 50;
	constexpr unsigned int FIZZ = 3;
	constexpr unsigned int BUZZ = 5;

	for (unsigned int i = 1; i <= TOTAL; i++)
	{
		std::string output = "";
		if (i % FIZZ == 0)
		{
			output.append("Fizz");
		}
		if (i % BUZZ == 0)
		{
			output.append("Buzz");
		}
		if (output == "")
		{
			output = std::to_string(i);
		}
		std::cout << output << "\n";
	}

	std::cin.get();
	return 0;
}