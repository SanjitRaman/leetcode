#include "../tools/leetcode_helper.h"

class Solution {
public:
	std::vector<int> findDuplicates(std::vector<int>& nums) {
		std::vector<int> duplicates;

		for (int& num : nums)
			// if the position in nums is already negative
			// we have seen position+1 before,
			// and since numbers only appear once or twice,
			// it means it has appeared twice.
			// so push position+1 to the output.
			if (nums[abs(num) - 1] < 0)
				duplicates.push_back(abs(num));
			else
				// we have not seen before, so make position 
				// that represents int negative
				nums[abs(num) - 1] *= -1;
		return duplicates;
	}
};

int main() {
	LeetcodeInput li;
	Solution s;

	std::vector<int> testcase;
	std::vector<int> duplicates;

	while (li.read_leetcode_list(&testcase)) {
		duplicates = s.findDuplicates(testcase);
		li.print_vector(duplicates);

		duplicates.clear();
		testcase.clear();
	}

	return 0;
}