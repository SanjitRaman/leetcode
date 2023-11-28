#include "../tools/leetcode_helper.h"
#include <unordered_map>

class Solution {
public:
	int numJewelsInStones(std::string jewels, std::string stones) {
		int num_jewels_in_stones = 0;
		std::unordered_map<char, int> stone_frequencies;
		for (const char& stone : stones) stone_frequencies[stone]++;

		// iterate through jewels
		// if jewel is a key in stone_frequencies
		// add stone_frequencies[jewel] to sum

		for (const char& jewel : jewels)
			if (stone_frequencies.find(jewel) != stone_frequencies.end())
				num_jewels_in_stones += stone_frequencies[jewel];

		return num_jewels_in_stones;
	}
};


int main() {
	LeetcodeInput li;
	Solution s;

	std::string jewels;
	std::string stones;

	for (int i = 0; i < 2; i++) {
		li.read_leetcode_string(&jewels);
		li.read_leetcode_string(&stones);
		std::cout << s.numJewelsInStones(jewels, stones) << std::endl;

		jewels.clear();
		stones.clear();
	}

	return 0;
}