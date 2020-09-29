#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::pair<std::string, unsigned int>> GetSubstringsFromString(const std::string& ORIGINAL, const unsigned int SUBSTRING_LENGTH)
{
	std::map<std::string, unsigned int> local_map;
	for (unsigned int i = 0; i < ORIGINAL.length() - SUBSTRING_LENGTH; i++)
	{
		std::string window;
		for (unsigned int j = 0; j < SUBSTRING_LENGTH; j++)
		{
			window += ORIGINAL[static_cast<long long>(i) + static_cast<long long>(j)];
		}
		local_map[window]++;
	}

	std::vector<std::pair<std::string, unsigned int>> local_vector;
	for (const auto& item : local_map)
	{
		local_vector.push_back(item);
	}
	return local_vector;
}

// Allows to sort a data type of std::pair of string and int
bool SortByValueDescending(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
	return (a.second > b.second);
}

int main()
{
	std::string OriginalString = "atcaatgatcaacgtaagcttctaagcatgatcaaggtgctcacacagtttatccacaacctgagtggatgacatcaagataggtcgttgtatctccttcctctcgtactctcatgaccacggaaagatgatcaagagaggatgatttcttggccatatcgcaatgaatacttgtgacttgtgcttccaattgacatcttcagcgccatattgcgctggccaaggtgacggagcgggattacgaaagcatgatcatggctgttgttctgtttatcttgttttgactgagacttgttaggatagacggtttttcatcactgactagccaaagccttactctgcctgacatcgaccgtaaattgataatgaatttacatgcttccgcgacgatttacctcttgatcatcgatccgattgaagatcttcaattgttaattctcttgcctcgactcatagccatgatgagctcttgatcatgtttccttaaccctctattttttacggaagaatgatcaagctgctgctcttgatcatcgtttc";
	const unsigned int SUBSTRING_LENGTH = 9;
	std::vector<std::pair<std::string, unsigned int>> substringVector = GetSubstringsFromString(OriginalString, SUBSTRING_LENGTH);

	// Sort the vector in descending order
	std::sort(substringVector.begin(), substringVector.end(), SortByValueDescending);

	for (const auto& item : substringVector)
	{
		std::cout << item.first << " " << item.second << "\n";
	}

	std::cin.get();
}