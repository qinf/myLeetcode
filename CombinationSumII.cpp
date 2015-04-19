/*
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 *   All numbers (including target) will be positive integers.
 *   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *   The solution set must not contain duplicate combinations.
 *   For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(num.begin(), num.end());
        dfs(num, 0, target, path, result);
        return result;
    }
private:
    void dfs(vector<int> &num, size_t start, int gap, vector<int> &path, vector<vector<int> > &result) {
        if (gap == 0) {
            result.push_back(path);
            return;
        }
        // prev保证只用一次
        int prev = -1;
        for (auto i = start; i < num.size(); i++) {
            if (gap < num[i]) return;
            if (prev == num[i]) continue;

            prev = num[i];

            path.push_back(num[i]);
            dfs(num, i + 1, gap - num[i], path, result);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> num = {2, 5, 2, 1, 2};
    vector<vector<int> > result;
    Solution s;
    result = s.combinationSum2(num, 5);
    for (auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
