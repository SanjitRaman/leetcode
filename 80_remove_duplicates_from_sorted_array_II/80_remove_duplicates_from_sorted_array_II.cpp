#include "../tools/leetcode_helper.h"

class Solution {
public:
	/*	
		 previously
		 for each element in the array
		 check if it is equal to the previous one
		 if so, do not increment the write_index
		 if not, write the value to write_index, and incr write_index
		 at the end return write_index.

		 this time, add the addition of a first? boolean
		 if the item is first to appear (not equal to the previous one, write)
		 if equal to previous one and first => write
		 if equal and not first => skip.
		 O(n) time.
	*/
	int removeDuplicates(std::vector<int>& nums) {


		bool first = true;
		int write_index = 1;

		for (int i = 1; i < nums.size(); i++) {

			if (nums[i] != nums[write_index - 1]) {
				nums[write_index] = nums[i];
				write_index++;
				first = true;
			}
			// equal to previous, and has only appeared once before.
			else if (first) {
				nums[write_index] = nums[i];
				write_index++;
				first = false;
			}
		}

		return write_index;
	}
};

int main() {
	// read inputs
	LeetcodeInput li;
	std::vector<int> nums;
	while (li.read_leetcode_list(&nums)) {
		
		// compute result
		Solution s;
		int k = s.removeDuplicates(nums);

		// print output
		li.print_vector(nums);
		std::cout << k << std::endl;
	}
}