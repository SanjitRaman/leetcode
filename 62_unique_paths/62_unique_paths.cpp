#include "../tools/leetcode_helper.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> row_below(n,1);
        
        // for each row:
        for(int i = 0; i < m-1; i++) {
            std::vector<int> curr_row(n, 1);
            // work from right to left
            for(int j = n-2; j >=0; j--) {
                curr_row[j] = curr_row[j+1] + row_below[j];
            }
            // set the row_below as the curr_row for the next iter.
            row_below = curr_row;
        }
        return row_below[0];
    }
};

int main() {
  Solution s;
  LeetcodeInput li;

  int m, n;
  while(li.read_integer(m)) {
    if(li.read_integer(n))
        li.print_integer(s.uniquePaths(m, n));
  }
  return 0;
}