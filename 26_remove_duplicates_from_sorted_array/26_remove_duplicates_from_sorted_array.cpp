#include "../tools/leetcode_helper.h"

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		int write_index = 1;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[write_index - 1]) {
				nums[write_index] = nums[i];
				write_index++;
			}
		}

		return write_index;
	}
};

int main() {
	// while there is input
	LeetcodeInput li;
	std::vector<int> nums;
	while (li.read_leetcode_list(&nums)) {

		// compute result
		Solution s;
		int k = s.removeDuplicates(nums);

		// print result
		li.print_vector(nums);
		std::cout << k << std::endl;
	}

}