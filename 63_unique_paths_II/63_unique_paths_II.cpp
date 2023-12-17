#include "../tools/leetcode_helper.h"

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        return 0;
    }
};

int main() {
  Solution s;
  LeetcodeInput li;

  std::vector<std::vector<int>> obstacleGrid;
  while(li.read_leetcode_list(obstacleGrid)) {
    li.print_integer(s.uniquePathsWithObstacles(obstacleGrid));
  }
  return 0;
}