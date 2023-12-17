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
		if (!s.empty()) {
			size_t start = s.find_first_of("\"") + 1;
			size_t end = s.find_last_of("\"");
			out = s.substr(start, end - start);
			return true;
		}
		else {
			return false;
		}
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

	void print_string(const std::string& s) {
		std::cout << "\"" << s << "\"" << std::endl;
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

	void print_vector(std::vector<std::vector<int>>& v) {
		std::cout << "[";
		if (v.empty()) {
			std::cout << "]" << std::endl;
			return;
		}

		for (int i = 0; i < v.size() - 1; i++) {
			std::cout << "[";
			for (int j = 0; j < v[i].size() - 1; j++) {
				std::cout << v[i][j] << ", ";
			}
			std::cout << v[i].back() << "], ";
		}

		std::cout << "[";
		for (int j = 0; j < v.back().size() - 1; j++) {
			std::cout << v.back()[j] << ", ";
		}
		std::cout << v.back().back() << "]]" << std::endl;
	}

	void print_integer(int i) {
		std::cout << i << std::endl;
	}
};
