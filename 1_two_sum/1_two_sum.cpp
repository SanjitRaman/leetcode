#include "../tools/leetcode_helper.h"
#include <unordered_map>


class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> indices;

		// assumes exactly one solution exists.

		// brute force solution
		// calculate the sum of each pair in nums
		// O(n^2)

		// solve this in O(n) time:
		// for each number in the array,
		// there is only one other number
		// that can be added to it to reach the target
		// x + y = target
		// know target.
		// so y = target-x
		// so store x in a hash table, with its index in nums
		// if y appears later in nums, then match with x.

		std::unordered_map<int, int> seen;

		for (int i = 0; i < nums.size(); i++) {
			int diff = target - nums[i];
			if (seen.find(diff) != seen.end()) // O(1) time
				return { seen[diff], i };
			else
				seen.insert(std::make_pair(nums[i], i));
		}

		return { };
	}
};


int main() {
	LeetcodeInput li;
	Solution s;

	std::vector<int> nums;
	int target;
	std::vector<int> indices;
	while (li.read_leetcode_list(&nums)) {
		target = li.read_integer();

		indices = s.twoSum(nums, target);

		li.print_vector(indices);

		nums.clear();
		indices.clear();
	}

	return 0;
}