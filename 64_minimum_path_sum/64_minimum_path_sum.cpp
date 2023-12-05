#include "../tools/leetcode_helper.h"
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int j = n-2; j>=0;j--) {
            grid[m-1][j] += grid[m-1][j+1];
        }
        for(int i = m-2; i >= 0; i--) {
            grid[i][n-1] += grid[i+1][n-1];
        }
        
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                grid[i][j] += std::min(grid[i+1][j], grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
    // top-down is faster because of fewer cache misses
    // due to storing in contiguous memory locations.
    int minPathSum2(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i-1]; 
        }
        for (int j = 1; j < m; j++) {
            grid[j][0] += grid[j-1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};


int main() {
  Solution s;
  LeetcodeInput li;

  std::vector<std::vector<int>> grid;
  while(li.read_leetcode_list(grid)) {
    li.print_integer(s.minPathSum(grid));
  }
  return 0;
}