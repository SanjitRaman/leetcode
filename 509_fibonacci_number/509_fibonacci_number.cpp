#include "../tools/leetcode_helper.h"

class Solution {
public:
    /*
    int solve(int n, std::vector<int>& dp) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(dp[n] == 0) dp[n] = solve(n-1, dp) + solve(n-2, dp);

        return dp[n];
    }

    int fib(int n) {
        
        //
        //SRTBOT
        //S: subproblems fib(i-1) and fib(i-2)
        //O: original: fib(n)
        //R: relate: fib(i) = fib(i-1) + fib(i-2)
        //T: topological order: start from i=0 increasing to n.
        //B: base: fib(0) = 0, fib(1) = 1
        //T: time: n * O(1) relations => O(n)
        
        if(n == 0) return 0;
        if(n == 1) return 1;

        std::vector<int> dp(n+1);

        // populate the table
        return solve(n, dp);
    }
    */
    /*
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        std::vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        // populate the dp table
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    */
    // since the dependency is only on prev and prev-prev
    // only store these values.
    int fib(int n) {
        if (n==0) return 0;
        else if (n==1) return 1;
        else {
            int a = 0, b = 1;
            int c;
            for (int i = 2; i <= n; i++) {
                c = a + b;
                a = b;
                b = c;
            }
            // at the end, c = F(n)
            return c;
        }
    }
};

int main() {

    LeetcodeInput li;
    Solution s;
    int n;
    while(li.read_integer(n)) {
        std::cout << s.fib(n) << std::endl;
    }

    return 0;
}