/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 *  All numbers (including target) will be positive integers.
 *  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *  The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path, result);
        return result;
    }
private:
    void dfs(vector<int> &candidates, size_t start, int gap, vector<int> &path, vector<vector<int> > &result) {
        if (gap == 0) {
            result.push_back(path);
            return;
        }
        for (auto i = start; i < candidates.size(); i++) {
            if (gap < candidates[i])    return;

            path.push_back(candidates[i]);
            dfs(candidates, i, gap - candidates[i], path, result);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> vec{8, 7, 4, 3};
    Solution s;
    vector<vector<int> > result = s.combinationSum(vec, 11);
    for (auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
