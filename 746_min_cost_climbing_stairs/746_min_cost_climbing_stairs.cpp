#include "../tools/leetcode_helper.h"
#include <algorithm>

class Solution {
public:
    // int minCostClimbingStairs(std::vector<int>& cost) {
    //     /*
    //     SRTBOT:
    //     S: subproblem: take 1 step or two steps
    //     R: relation:
    //         suppose at stair i, one has paid cost c.
    //         then two choices occur:
    //         take 1 step:
    //             c1 += cost[i] + minCostClimbingStairs(cost[i+1:])
    //         take 2 steps:
    //             c2 += cost[i] + minCostClimbingStairs(cost[i+2:])
    //         the choice we want to take is the minimum of the two costs.
    //         c += min(c1, c2);
    //     O: Original:
    //         c(cost[0...n]) <=> solve(0, cost)
    //     T: topological order:
    //         requires calculating cost[i:] for all i 0...n.
    //         so start from i = n and decrease.
    //     B: base:
    //         c(cost = [k]) = k
    //         c(cost = [k,j]) = k
    //     T: time:
    //         n * O(1) relation so O(n) time.
    //     */
    //    int n = cost.size();
    //    // base
    //    if(n == 1) return cost[0];
    //    if(n == 2) return cost[0] < std::min(cost[0], cost[1]); // can choose where to start.
    //    std::vector<int> dp(n, -1);
    //    for(int i = 3; i < )
    //    return solve(0, cost, dp);
    // }

    // int minCostClimbingStairs(std::vector<int>& cost) {
    //     int n = cost.size();
    //     if(n == 0) return 0;
    //     else if (n == 1) return cost[0];
    //     else {
    //         int two = 0, one = cost[n-1], c;
    //         for(int i = n-2; i >= 0; i--) {
    //             c = std::min(cost[i] + one, cost[i] + two);
    //             two = one;
    //             one = c;
    //         }
    //         return std::min(c, one);
    //     } 
    // } 
    // dp array in place:
    int minCostClimbingStairs(std::vector<int>& cost) {
        cost.push_back(0);

        for(int i = cost.size()-3; i >= 0; i--) {
            cost[i] += std::min(cost[i+1], cost[i+2]);
        }
        return std::min(cost[0], cost[1]);
    }

};

int main() {

    LeetcodeInput li;
    Solution s;
    std::vector<int> cost;
    while(li.read_leetcode_list(cost)) {
        std::cout << s.minCostClimbingStairs(cost) << std::endl;
    }

    return 0;
}