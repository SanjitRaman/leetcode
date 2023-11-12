#include <iostream>
#include <vector>
#include "..\tools\leetcode_helper.h"

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		int index = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[index] = nums[i];
				index++;
			}
		}
		return index;
	}
};

int main() {

	// read inputs
	LeetcodeInput li;

	std::vector<int> nums = li.read_leetcode_list();
	int val = li.read_integer();


	// solve
	Solution s;
	int k = s.removeElement(nums, val);


	// print output
	std::cout << k << std::endl;


	return(0);
}