#include "../tools/leetcode_helper.h"
#include <unordered_map>
#include <algorithm>

class Solution {
public:

    std::unordered_map<int, int> Counter(std::vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        else {
            std::unordered_map<int, int> result;
            for(int i = 0; i < nums.size(); i++) {
                if(result.find(nums[i]) == result.end()) {
                    result.insert(std::make_pair(nums[i], 1));
                } else {
                    result[nums[i]] += 1;
                }
            }
            return result;
        }
    }

    int removeDuplicates(std::vector<int>& nums) {
        int write_index = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[write_index-1]) {
                nums[write_index] = nums[i];
                write_index++;
            }
        }
        return write_index;
    }

    int deleteAndEarn(std::vector<int>& nums) {
        // sort O(nlogn)
        std::sort(nums.begin(), nums.end());
        // count O(n)
        std::unordered_map count = Counter(nums);
        // remove duplicates O(n), return the size as n.
        int n = removeDuplicates(nums);

        int earn1 = 0, earn2 = 0, curEarn;
        for(int i = 0; i < n; i++) {
            curEarn = nums[i] * count[nums[i]];
            if( i > 0 && nums[i] == nums[i-1] + 1) { // adjacent, only include one of them
                curEarn = std::max(curEarn + earn1, earn2);
            } else { // non-adjacent, include both
                curEarn = curEarn + earn2;
            }
            earn1 = earn2;
            earn2 = curEarn;
        }
        return earn2;
    }
};

int main() {
  Solution s;
  LeetcodeInput li;

  std::vector<int> nums;
  while(li.read_leetcode_list(&nums)) {
    li.print_integer(s.deleteAndEarn(nums));
  }
  return 0;
}
