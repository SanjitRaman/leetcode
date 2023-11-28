#include "../tools/leetcode_helper.h"
#include <unordered_map>

class Solution {
public:
	std::vector<std::string> findWords(std::vector<std::string>& words) {
		// initialize a map of keyboard keys to rows
		// for every word in words
		//     check if all characters of word belong to same row of keyboard.
		//         if so add word to result

		std::vector<std::string> constructable_words;

		std::unordered_map<char, int> key_to_row_map;
		std::vector<std::string> keyboard_rows = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };

		for (int i = 0; i < keyboard_rows.size(); i++) {
			for (char& ch : keyboard_rows[i]) {
				key_to_row_map.insert(std::make_pair(ch, i));             // lowercase
				key_to_row_map.insert(std::make_pair(ch - 'a' + 'A', i)); // capitals
			}
		}

		for (std::string& word : words) {
			if (word.size() == 0) continue;

			int first_char_row = key_to_row_map[word[0]];
			bool same_row = true;
			for (int i = 1; i < word.size(); i++)
				if (key_to_row_map[word[i]] != first_char_row) {
					same_row = false;
					break;
				}
			if (same_row) constructable_words.push_back(word);
		}

		return constructable_words;
	}
};

int main() {

	LeetcodeInput li;
	Solution s;

	std::vector<std::string> words;
	while (li.read_leetcode_list(&words)) {
		std::vector<std::string> result = s.findWords(words);
		li.print_vector(result);
		words.clear();
	}

	return 0;
}