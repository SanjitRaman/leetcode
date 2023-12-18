#include "../tools/leetcode_helper.h"
#include <algorithm>

class Solution
{
public:
    // can choose:
    // row below: i or i+1
    // if I know the answer to row below i and i+1
    // then I choose the lowest of the two.
    // work from the bottom up.
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        int numRows = triangle.size();

        // Initialize a row with the size of numRows + 1 and fill it with 0s
        std::vector<int> minPathSums(numRows + 1, 0);

        // Start from the bottom of the triangle
        for (int rowIndex = numRows - 1; rowIndex >= 0; rowIndex--)
        {
            // For each element in the current row
            for (int i = 0; i <= rowIndex; i++)
            {
                // Update the minimum path sum to reach this element
                minPathSums[i] = triangle[rowIndex][i] + std::min(minPathSums[i], minPathSums[i + 1]);
            }
        }

        // The minimum path sum to reach the top of the triangle is now in minPathSums[0]
        return minPathSums[0];
    }
};

int main()
{
    Solution s;
    LeetcodeInput li;

    std::vector<std::vector<int>> triangle;
    while (li.read_leetcode_list(triangle))
    {
        li.print_integer(s.minimumTotal(triangle));
    }
    return 0;
}