#include <iostream>
#include <vector>
#include "..\tools\leetcode_helper.h"

using namespace std;


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int  i = m - 1;
		int  j = n - 1;
		int  k = n + m - 1;

		while (i >= 0 && j >= 0)
			if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
			else nums1[k--] = nums2[j--];

		while (j >= 0)
			nums1[k--] = nums2[j--];
	}
};

int main()
{
	LeetcodeInput li;
	std::vector<int> nums1;
	while (li.read_leetcode_list(&nums1)) {
		int m = li.read_integer();

		std::vector<int> nums2;
		li.read_leetcode_list(&nums2);

		int n = li.read_integer();


		Solution sol;

		sol.merge(nums1, m, nums2, n);

		for (int i = 0; i < m + n; i++) {
			std::cout << nums1[i] << " ";
		}

	}

	return 0;
}