#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>

class LeetcodeInput {
public:
	
	/// initialise the vector v to the values passed in via cin.
	bool read_leetcode_list(std::vector<int> * v) {
		std::string s;
		std::getline(std::cin, s);
		if (s != "") {
			std::istringstream ss{ std::regex_replace(s, std::regex{R"(\[|\]|,)"}, " ") };
			*v = { std::istream_iterator<int>{ss}, std::istream_iterator<int>{} };
			return true;
		}
		else {
			return false;
		}

	}

	/// Reads a single integer from a line containing one integer.
	int read_integer() {
		std::string s;
		std::getline(std::cin, s);

		return std::stoi(s);

	}

	void print_vector(std::vector<int>& v) {
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}
};
