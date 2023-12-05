#include "../tools/leetcode_helper.h"

class Solution {
public:
    /*
    int solve(int n, std::vector<int>& dp) {
        if (n == 0) return 0;
        if (n <= 2) return 1;

        // populate the table
        if(dp[n] == 0) dp[n] = solve(n-1,dp) + solve(n-2, dp) + solve(n-3, dp);
        
        return dp[n];
    }

    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;

        std::vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        return solve(n, dp);
    }
    */
   /*
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;

        std::vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        // populate the table
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
    */
    
    int tribonacci(int n) {
        if     (n == 0) return 0;
        else if(n <= 2) return 1;
        else {
            int a=0,b=1,c=1,d;
            for(int i = 3; i <= n; i++) {
                d = a + b + c;
                a = b;
                b = c;
                c = d;
            }
            return d;
        }
    }
};

int main() {

    LeetcodeInput li;
    Solution s;
    int n;
    while(li.read_integer(n)) {
        std::cout << s.tribonacci(n) << std::endl;
    }

    return 0;
}