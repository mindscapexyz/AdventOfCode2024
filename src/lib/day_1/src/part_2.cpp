#include <day_1/common.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

int main() {
	std::vector<int> left, right;
	long dist = 0;
	try {
		//day_1::parseInput("test-input.txt", left, right);
		day_1::parseInput("input.txt", left, right);
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
		return 1;
	}

	size_t numPairs = left.size();
	std::cout << numPairs << '\n';

	for (size_t i = 0; i < numPairs; i++) {
		int templ = day_1::findAndEjectMin(left);
		int found = day_1::countOccurrences(right, templ);
		dist += found * templ;
		// std::cout << "most min left:" << " " << templ << "; most min right:" << " " << tempr << '\n';
	}
	std::cout << dist << '\n';

	return 0;
}