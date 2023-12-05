#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>

class LeetcodeInput {
public:
	
	/// initialise the vector v to the values passed in via cin.
	bool read_leetcode_list(std::vector<int>& v) {
		v.clear();
		std::string s;
		std::getline(std::cin, s);
		if (s != "") {
			std::istringstream ss{ std::regex_replace(s, std::regex{R"(\[|\]|,)"}, " ") };
			v = { std::istream_iterator<int>{ss}, std::istream_iterator<int>{} };
			return true;
		}
		else {
			return false;
		}

	}

	bool read_leetcode_list(std::vector<std::vector<int>>& v) {
		// Clear the vector before reading new values
    	v.clear();

		std::string input;
		std::getline(std::cin, input);

		if (input.empty()) return false;

		std::istringstream iss(input);

		char c;
		iss >> c; // Read the first '['
		while (iss >> c && c != ']') {
			if (c == '[') {
				std::vector<int> rowValues;
				int num;
				while (iss >> num) {
					rowValues.push_back(num);
					if (iss.peek() == ',') {
						iss.ignore(); // Ignore the comma
					}
					else if (iss.peek() == ' ') {
						iss.ignore(); // Ignore the space
					}
					else if (iss.peek() == ']') {
						iss.ignore(); // Ignore the closing bracket
						break;
					}
				}
				v.push_back(rowValues);
			}
			if (iss.peek() == ',') {
				iss.ignore(); // Ignore the comma between lists
			}
		}

		return true;
	}

	bool read_leetcode_list(std::vector<std::vector<int>>& v) {
		std::string s;
		std::getline(std::cin, s);

		if (s.empty()) {
			return false;
		}

		// Remove '[' and ']', replace ',' and any whitespace with ' ' to create a space-separated string
		std::string cleanedString = std::regex_replace(s, std::regex{R"(\[|\]|\s)"}, "");
		cleanedString = std::regex_replace(cleanedString, std::regex{R"(,)"}, " ");

		// Use a string stream to read integers from the cleaned string
		std::istringstream ss(cleanedString);

		// Use two nested loops to read integers into the 2D vector
		int num;
		while (ss >> num) {
			v.emplace_back(); // Add a new row
			v.back().push_back(num); // Add the first element of the row

			// Read the remaining elements of the row
			while (ss.peek() == ' ') {
				ss.ignore();
				ss >> num;
				v.back().push_back(num);
			}
		}

		return true;
	}


	bool read_leetcode_list(std::vector<std::string>& v) {
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
				v.push_back(token);
			}
			else if (ch == ',') {
				// Handle comma between strings (skip commas outside quotes)
				continue;
			}
		}

		return true;

	}

	bool read_leetcode_string(std::string& out) {
		out.clear();
		std::string s;
		std::getline(std::cin, s);
		if (s != "") {
			std::istringstream ss{ std::regex_replace(s, std::regex{R"(\")"}, " ") };
			out = { std::istream_iterator<char>{ss}, std::istream_iterator<char> {} };
			return true;
		}
		else return false;
	}

	/// Reads a single integer from a line containing one integer.
	bool read_integer(int& n) {
		std::string s;
		std::getline(std::cin, s);
		if(s != "") {
			std::istringstream ss{ s };
			n = std::stoi(s);
			return true;
		}
		else return false;

	}

	//int read_string(std::istringstream ss) {

	//}

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

	void print_integer(int i) {
		std::cout << i << std::endl;
	}
};
