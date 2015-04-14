/* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using std::cout; using std::endl;
using std::map; using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> path;
        map<int, int> map_count;
        for (auto i : num) {
            ++map_count[i];
        }
        dfs(num, path, map_count, result);
        return result;
    }
/*
 * 为啥要遍历map而不是遍历num?
 */
private:
    void dfs(const vector<int> &num, vector<int> &path, const map<int, int> &map_count, vector<vector<int> > &result) {
        if (path.size() == num.size())
            result.push_back(path);
        for(auto &p : map_count) {
            auto times = count(path.begin(), path.end(), p.first);
            if (times < p.second) {
                path.push_back(p.first);
                dfs(num, path, map_count, result);
                path.pop_back();
            }
        }
    }
};

int main() {
    vector<int> num = {1, 1, 2};
    vector<vector<int> > result;
    Solution s;
    result = s.permuteUnique(num);
    for (auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
