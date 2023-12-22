#include "../tools/leetcode_helper.h"

class Solution
{
public:
    int calculateSquare(int currValue, int cellDiagonalLeft, int cellBelow, int cellDiagonalRight)
    {
        return currValue + std::min(cellDiagonalLeft, std::min(cellBelow, cellDiagonalRight));
    }

    int minFallingPathSum(std::vector<std::vector<int>> &matrix)
    {
        int numRows = matrix.size();
        std::vector<int> currRow = matrix[numRows - 1];

        // insert maxElement at the front and the back of currRow
        int maxElement = 101; // Replace with actual maximum element if known
        currRow.insert(currRow.begin(), maxElement);
        currRow.push_back(maxElement);

        int prevValue = 101;

        for (int rowIndex = numRows - 2; rowIndex >= 0; rowIndex--)
        {
            for (int i = 1; i < numRows; i++)
            {
                currRow[i] = calculateSquare(matrix[rowIndex][i], prevValue, currRow[i + 1], currRow[i + 2]);
                prevValue = currRow[i];
            }
            currRow[numRows] = calculateSquare(matrix[rowIndex][numRows - 1], prevValue, );
        }

        // find the minimum element of currRow to get the minFallingPathSum.
        return *std::min_element(currRow.begin() + 1, currRow.end() - 1);
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