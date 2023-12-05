#include "../tools/leetcode_helper.h"
#include <unordered_map>

class Solution {
private:
    // std::unordered_map<int, int> ways_computed;
public:
    // int climbStairs(int n) {
    //     // SRTBOT:
    //     // subprobs: Ways(i) = number of ways of reaching stair i, for 1 <= i <= n
    //     // Original: Ways(n) = number of ways of reaching nth stair
    //     // Relate: how can I get to i ?
    //     //         - take 1 step from position i-1
    //     //         - take 2 steps from position i-2
    //     //         therefore Ways(i) = Ways(i-1) + Ways(i-2)
    //     // Topo order: i = 0 increasing.
    //     // Base: Ways(0) = 1, Ways(1) = 1
    //     // Time = n * O(1) = O(n)
    //         if (ways_computed.find(n) != ways_computed.end()) {
    //             return ways_computed[n];
    //         } else if (n == 0 || n == 1) {
    //             ways_computed.insert(std::make_pair(n, 1));
    //             return 1;
    //         } else {
    //             int ways_n = climbStairs(n - 1) + climbStairs(n - 2);
    //             ways_computed.insert(std::make_pair(n, ways_n));
    //             return ways_n;
    //         }
    //     // review:
    //     // dont need unordered map, just store as array.
    //     // can always store memo in climbStairs function
    //     // and have a solve function to do the computation.
    // }
    
    // int climbStairs(int n) {
        
    //     if (n==0) return 0;
    //     else if (n==1) return 1;
    //     else if (n==2) return 2;
    //     else {
    //         std::vector<int> ways(n+1, -1);
    //         ways[n] = 1;
    //         ways[n-1] = 1;

    //         for(int i = n-2; i >= 0; i--) {
    //             ways[i] = ways[i+1] + ways[i+2];
    //         }

    //         return ways[0];
    //     }
    //  // O(n) time, O(n) space

    // }

    // This can be optimised further by noticing that 
    // ways[i] only depends on ways[i+1] and ways[i+2]
    // so only store ways[i+1] and ways[i+2]

    int climbStairs(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 2;
        else {
            int one = 1, two = 1, c;
            for(int i = n-2; i >= 0; i--) {
                c = one + two;
                one = two;
                two = c;
            }
            return c;
        }
    }
    // O(n) time, O(1) space.
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