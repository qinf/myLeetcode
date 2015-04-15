/*
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::endl; using std::cout;
using std::vector; using std::sort;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> path;
        bfs(num, path, result);
        return result;
    }
private:
    void bfs(const vector<int> &num, vector<int> &path, vector<vector<int> > &result) {
        if (path.size() == num.size()) {
            result.push_back(path);
            return;
        }

        for (auto i : num) {
            if (find(path.begin(), path.end(), i) != path.end())
                continue;
            path.push_back(i);
            bfs(num, path, result);
            path.pop_back();
        }
    }
};
int main() {
    Solution s;
    vector<int> num = {1, 2, 3};
    vector<vector<int> > result = s.permute(num);
    for (auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout <<endl;
    }
    return 0;
}
