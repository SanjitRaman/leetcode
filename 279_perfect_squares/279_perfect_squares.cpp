#include "../tools/leetcode_helper.h"
#include <unordered_map>
#include <cmath>

class Solution {
public:

    int solve(int x, std::unordered_map<int, int>& dp, std::vector<int>& c) {
        if (dp.find(x) != dp.end()) { // found in dp.
            return dp[x];
        }
        else {
            // compute
            // iterate over vector c
            int best_sol = -1;
            int solution;
            for(int k = 0; k < c.size(); k++) {
                if(x-c[k] >= 0) {
                    solution = solve(x-c[k], dp, c);
                    if (best_sol == -1 || solution < best_sol)
                        best_sol = solution;
                }
            }
            best_sol++; // 1 more for the count of the coin we just added.
            dp.insert(std::make_pair(x,best_sol));  
            return best_sol; 
        }
    }

    int numSquares(int n) {
        // this is like the coin change problem
        // take the highest denomination you can first.
        
        // so try a 
        // greedy algo:
        // always start with the largest coin you can
        // assume the coins are sorted in decreasing size:
        // for (k=1 to n) 
        //      m_k = floor(x/ck) # number of coin ck
        //      x -= mk*ck
        // only works for canonical systems.
        // by counterexample:
        // 12: 4 4 4 is a better solution that 9 1 1 1
        // Hence it is not canonical and a greedy algorithm will not work.


        // instead, use a
        // dynamic programming approach
        // M(x) = smallest number of coins to reach target x
        // M(x) = min_k=1...n { 1 + M(x-c_k) } c_k is the value of the coin we just added.
        // complexity is O(n) * O(x) = O(nx)
        
        // create a vector storing squares for the non-canonical system upto sqrt(n)
        // allowed to use sqrt() as the overall solution will be faster than O(n).
        std::vector<int> c;
        for(int i  = 1; i <= std::sqrt(n); i++) 
            c.push_back(i*i);
        
        std::unordered_map<int, int> dp;
        dp.insert(std::make_pair(1,1));


        return solve(n, dp, c);

    }
};

int main() {
  Solution s;
  LeetcodeInput li;

  int n;
  while(li.read_integer(n)) {
    li.print_integer(s.numSquares(n));
  }
  return 0;
}