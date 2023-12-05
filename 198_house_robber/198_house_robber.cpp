#include "../tools/leetcode_helper.h"
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        // SRTBOT:
        // subproblems: F(i) is the maximum money can be robbed without alerting police starting from house i onwards.
        // Relate: F(i) = max(nums[i] + F(i+2), F(i+1))
        // T: each relationship on i depends on knowing solution to i+1 and i+2.
        //    so start at end, and decrement i.
        // B: base:
        //    if i == nums.size()-2: max(nums[i], nums[i+1])
        // O: original problem:
        //    F(0)
        // Time: loop through n elements, and O(1) operations, so O(n).
        int n = nums.size();
        if(n == 2) return std::max(nums[0], nums[1]);
        else {
            nums.push_back(0);
            for(int i = n-2; i >= 0; i--) {
                nums[i] = std::max(nums[i] + nums[i+2], nums[i+1]);
            }
        }
        return nums[0];
    }
};


int main() {
  Solution s;
  LeetcodeInput li;

  std::vector<int> nums;
  while(li.read_leetcode_list(&nums)) {
    li.print_integer(s.rob(nums));
  }
  return 0;
}