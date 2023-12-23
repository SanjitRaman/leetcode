#include "../tools/leetcode_helper.h"
#include <limits>

class Solution
{
public:
    int min3(int a, int b, int c)
    {
        return std::min(a, std::min(b, c));
    }

    int minFallingPathSum(std::vector<std::vector<int>> &matrix)
    {
        int n = matrix.size();

        std::vector<int> dp(n + 2, 10001);
        for (int i = 0; i < n; i++)
            dp[i + 1] = matrix[n - 1][i];

        int prevComputedValue, computedValue;
        for (int r = n - 2; r >= 0; r--)
        {
            int prevComputedValue = matrix[r][0] + min3(dp[0], dp[1], dp[2]);
            for (int c = 1; c < n; c++)
            {
                computedValue = matrix[r][c] + min3(dp[c], dp[c + 1], dp[c + 2]);
                dp[c] = prevComputedValue;
                prevComputedValue = computedValue;
            }
            dp[n] = computedValue;
        }

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