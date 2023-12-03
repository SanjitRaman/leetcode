#include "../tools/leetcode_helper.h"
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> ways_computed;
public:
    int climbStairs(int n) {
        // SRTBOT:
        // subprobs: Ways(i) = number of ways of reaching stair i, for 1 <= i <= n
        // Original: Ways(n) = number of ways of reaching nth stair
        // Relate: how can I get to i ?
        //         - take 1 step from position i-1
        //         - take 2 steps from position i-2
        //         therefore Ways(i) = Ways(i-1) + Ways(i-2)
        // Topo order: i = 0 increasing.
        // Base: Ways(0) = 1, Ways(1) = 1
        // Time = n * O(1) = O(n)
            if (ways_computed.find(n) != ways_computed.end()) {
                return ways_computed[n];
            } else if (n == 0 || n == 1) {
                ways_computed.insert(std::make_pair(n, 1));
                return 1;
            } else {
                int ways_n = climbStairs(n - 1) + climbStairs(n - 2);
                ways_computed.insert(std::make_pair(n, ways_n));
                return ways_n;
            }
        // review:
        // dont need unordered map, just store as array.
        // can always store memo in climbStairs function
        // and have a solve function to do the computation.
    }
};

int main() {

    Solution s;
    LeetcodeInput li;
    int n;
    while(li.read_integer(&n)) {
        std::cout << s.climbStairs(n) << std::endl;
    }

    return 0;
}