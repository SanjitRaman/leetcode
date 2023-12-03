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

	bool read_leetcode_list(std::vector<std::string>* v) {
		std::string input;

		std::getline(std::cin, input);

		if (input.empty()) return false;

		// Remove brackets
		input.erase(std::remove(input.begin(), input.end(), '['), input.end());
		input.erase(std::remove(input.begin(), input.end(), ']'), input.end());

		std::istringstream iss(input);

		char ch;
		std::string token;

		while (iss.get(ch)) {
			if (ch == '\"') {
				token.clear();
				while (iss.get(ch) && ch != '\"') {
					token += ch;
				}
				v->push_back(token);
			}
			else if (ch == ',') {
				// Handle comma between strings (skip commas outside quotes)
				continue;
			}
		}

		return true;

	}

	bool read_leetcode_string(std::string* out) {
		std::string s;
		std::getline(std::cin, s);
		if (s != "") {
			std::istringstream ss{ std::regex_replace(s, std::regex{R"(\")"}, " ") };
			*out = { std::istream_iterator<char>{ss}, std::istream_iterator<char> {} };
			return true;
		}
		else return false;
	}

	/// Reads a single integer from a line containing one integer.
	bool read_integer(int* n) {
		std::string s;
		std::getline(std::cin, s);
		if(s != "") {
			std::istringstream ss{ s };
			*n = std::stoi(s);
			return true;
		}
		else return false;

	}

	int read_string(std::istringstream ss) {

	}

	void print_vector(std::vector<int>& v) {
		if (v.empty()) {
			std::cout << "[]" << std::endl;
			return;
		}
		std::cout << "[";
		for (int i = 0; i < v.size()-1; i++) {
			std::cout << v[i] << ", ";
		}
		std::cout << v.back() << "]" << std::endl;

		return;
	}

	void print_vector(std::vector<std::string>& v) {
		std::cout << "[";
		if (v.empty()) {
			std::cout << "]" << std::endl;
			return;
		}

		for (int i = 0; i < v.size()-1; i++) {
			std::cout << "\"" << v[i] << "\", ";
		}
		std::cout << "\"" << v.back() << "\"]" << std::endl;

		return;
	}
};
