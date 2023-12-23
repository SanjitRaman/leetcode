#include "../tools/leetcode_helper.h"

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

        std::vector<int> dp(n + 2, 101);
        std::vector<int> dp2 = dp;
        for (int i = 0; i < n; i++)
            dp[i + 1] = matrix[n - 1][i];

        for (int r = n - 2; r >= 0; r--)
        {
            for (int c = 0; c < n; c++)
            {
                std::cout << "r: " << r << " c: " << c << std::endl;
                dp2[c + 1] = matrix[r][c] + min3(dp[c], dp[c + 1], dp[c + 2]);
            }
            dp2[n] = matrix[r][n - 1] + min3(dp[n - 1], dp[n], dp[n + 1]);

            dp = dp2;
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