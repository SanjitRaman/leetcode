#include "../tools/leetcode_helper.h"
#include <unordered_map>

struct pairHash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T,U> &x) const {
        auto hash1 = std::hash<T>{}(x.first);
        auto hash2 = std::hash<U>{}(x.second);
       
        if(hash1 != hash2) {
            return hash1 ^ hash2;
        }
        // if hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

class Solution {
private:
    int m,n;

public:

    int dfs(std::pair<int, int> coord, std::vector<std::vector<int>>& obstacleGrid, std::unordered_map<std::pair<int,int>, int, pairHash>& dp) {
        // out of bounds or an obstacle
        int r = coord.first;
        int c = coord.second;
        if(r == m || c == n || obstacleGrid[r][c] == 1) {
            return 0;
        }
        // found in dp
        else if(dp.find(coord) != dp.end()) {
            return dp[coord];
        }
        // else not found in dp
        else {
            // calculate the current cell as the sum of below and to the right.
            int curr_cell = dfs(std::make_pair(r+1,c), obstacleGrid, dp) + dfs(std::make_pair(r,c+1), obstacleGrid, dp);
            dp.insert({coord, curr_cell});
            return curr_cell;
        }
    }

    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();    // num. rows
        n = obstacleGrid[0].size(); // num. cols

        std::unordered_map<std::pair<int,int>, int, pairHash> dp;

        dp.insert({std::make_pair(m-1,n-1), 1});
        // do a DFS:
        // the number of paths for the current node
        // if the current node is an obstacle:
        //      uniquepaths for that node is 0.
        // else:
        //      is the sum of the nodes of the right and below nodes.
        //          if you go out of bounds return 0.
        //          if you are at the destination return 1.
        //      if each is not an obstacle

        return dfs(std::make_pair(0,0), obstacleGrid, dp);


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