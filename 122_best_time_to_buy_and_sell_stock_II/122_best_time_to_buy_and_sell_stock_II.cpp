#include "..\tools\leetcode_helper.h"

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		// sum of all non-decreasing subsequences of a vector. 
		// Time Complexity: O(n)
		// Space Complexity: O(1)
		
		int n = prices.size();

		if (n <= 1) {
			return 0;
		}

		int profit = 0; 
		int buy_day = 0, sell_day = 0;


		// loop through the array
		for (int i = 1; i < n; i++) {
			// if the current day has higher price, we should sell later.
			if (prices[i] >= prices[i - 1]) {
				sell_day++;
			}
			// else we are at a lower price, so collect the profit of the previous day.
			// then start searching for a new non-decreasing subsequence.
			else {
				profit += prices[sell_day] - prices[buy_day];
				buy_day = sell_day = i;
			}
		}
			// if we haven't sold yet (no dip), sell at the last day to maximise the profit.
			profit += prices[sell_day] - prices[buy_day];

		return profit;
	}
};

int main() {

	LeetcodeInput li;
	std::vector<int> prices;

	// while input exists
	while (li.read_leetcode_list(&prices)) {

		// compute
		Solution s;
		int max_profit = s.maxProfit(prices);

		// print output
		std::cout << max_profit << std::endl;
	}

	return 0;

}