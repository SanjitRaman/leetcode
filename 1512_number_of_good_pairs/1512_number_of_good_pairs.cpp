#include "../tools/leetcode_helper.h"
#include <unordered_map>

class Solution {
public:
	int numIdenticalPairs(std::vector<int>& nums) {
		int goodpairs = 0;

		// Create a map to store the occurences of each unique integer.
		std::unordered_map<int, int> frequencies;

		// Iterate through the vector and update the map.
		for (int i = 0; i < nums.size(); i++) frequencies[nums[i]]++;

		// for an integer x appearing c times,
		// the number of good pairs that can be made
		// is c * (c-1) / 2

		// Iterate through the map and calculate the number of good pairs:
		for (int i = 0; i < frequencies.size(); i++) {
			int c = frequencies[i];
			goodpairs += c * (c - 1) / 2;
		}

		return goodpairs;
	}
};


int main() {
	LeetcodeInput li;
	Solution s;

	std::vector<int> v;

	for (int i = 0; i < 3; i++) {
		li.read_leetcode_list(v);
		int goodpairs = s.numIdenticalPairs(v);
		std::cout << goodpairs << std::endl;
		v.clear();
	}

}