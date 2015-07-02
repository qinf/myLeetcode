/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int N = prices.size();
        if (N == 0) return 0;
        int profit = 0;
        int minPrice = prices[0];
        for (int i = 0; i < N; ++i) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {100, 90, 130, 120};
    int profit = s.maxProfit(prices);
    cout << profit << endl;
};
