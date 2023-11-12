#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>

class LeetcodeInput {
public:
	std::vector<int> read_leetcode_list() {
		std::string s;

		std::getline(std::cin, s);

		std::istringstream ss{ std::regex_replace(s, std::regex{R"(\[|\]|,)"}, " ") };
		std::vector<int> v{ std::istream_iterator<int>{ss}, std::istream_iterator<int>{} };

		return v;
	}

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
