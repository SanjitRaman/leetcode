#include "../tools/leetcode_helper.h"

class Solution
{
public:
    int minFallingPathSum(std::vector<std::vector<int>> &matrix)
    {
        int n = matrix.size();

        // Initialize dp array with a large value
        std::vector<int> dp(n + 2, 10001);

        // Initialize the last row of dp array with the values from the last row of the matrix
        for (int i = 0; i < n; i++)
            dp[i + 1] = matrix[n - 1][i];

        int prevComputedValue, computedValue;
        for (int r = n - 2; r >= 0; r--)
        {
            // Compute the minimum falling path sum for each element in the current row
            prevComputedValue = matrix[r][0] + std::min({dp[0], dp[1], dp[2]});
            for (int c = 1; c < n; c++)
            {
                computedValue = matrix[r][c] + std::min({dp[c], dp[c + 1], dp[c + 2]});
                dp[c] = prevComputedValue;
                prevComputedValue = computedValue;
            }
            dp[n] = computedValue;
        }

        // Find the minimum falling path sum from the first row of the dp array
        return *std::min_element(dp.begin() + 1, dp.end() - 1);
    }
};

int main()
{
    Solution s;
    LeetcodeInput li;

    std::vector<std::vector<int>> matrix;
    while (li.read_leetcode_list(matrix))
    {
        li.print_integer(s.minFallingPathSum(matrix));
    }
    return 0;
}