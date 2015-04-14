/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 *  ]
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout; using std::endl;
using std::vector; using std::find;

//递归
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> num;
        for (auto i = 0; i != n; i++)
            num.push_back(i+1);
        vector<int> path;
        vector<vector<int> > result;
        dfs(num, path, k, result);
        return result;
    }
private:
    void dfs(const vector<int> &num, vector<int> &path, const int k, vector<vector<int> > &result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for(auto i : num) { // 优化可以从多传一个数字表示当前 for(int i = start; i <= n; ++i)
            if (find(path.begin(), path.end(), i) == path.end()) {
                if (path.empty() || i > path.back()) {
                    path.push_back(i);
                    dfs(num, path, k, result);
                    path.pop_back();
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int> > result = s.combine(4, 2);
    for(auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
