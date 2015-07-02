/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you
 * like (ie, buy one and sell one share of the stock multiple times). However, you may not engage
 * in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int N = prices.size();
        if (N < 2) return 0;
        vector<bool> visited(N, true);
        int total_profit = 0;
        int max_profit_pos = 0;
        int min_profit_pos = 0;
        for (int i = 0; i < N / 2; ++i) {
            int profit = 0;
            int minPrice = 0;
            for (int j = 0; j < N; ++j) {
                if (visited[j]) {
                    min_profit_pos = j;
                    minPrice = prices[j];
                    break;
                }
            }
            int old_profit = profit;
            int old_min_price = minPrice;
            for (int j = 0; j < N; ++j) {
                if (!visited[j])
                    continue;
                if (minPrice > prices[j]) {
                    min_profit_pos = j;
                }
                profit = max(profit, prices[j] - minPrice);
                minPrice = min(minPrice, prices[j]);
                if (old_profit < profit) {
                    max_profit_pos = j;
                }
            }
            visited[max_profit_pos] = false;
            visited[min_profit_pos] = false;
            total_profit += profit;
        }
        return total_profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {100, 90, 130, 120};
    prices.clear();
    for (int i = 1; i <= 10000; i++)
        prices.push_back(i);
    int profit = s.maxProfit(prices);
    cout << profit << endl;
    return 0;
}
