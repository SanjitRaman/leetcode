#include "../tools/leetcode_helper.h"

class Solution {
public:
    // this could be improved by only storing the previous row and curr row.
    int  longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length();
        int n = text2.length();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1,0));

        for(int i = m-1; i >= 0; i--)
            for(int j = n-1; j >= 0; j--)
                if(text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else 
                    dp[i][j] = std::max(dp[i][j+1], dp[i+1][j]);

        return dp[0][0];
    }
};

int main() {
  Solution s;
  LeetcodeInput li;

  std::string text1, text2;
  while(li.read_leetcode_string(text1)) {
    if(!li.read_leetcode_string(text2))
        std::cerr << "Error reading in text2" << std::endl;
    
    li.print_integer(s.longestCommonSubsequence(text1, text2));
  }
  return 0;
}