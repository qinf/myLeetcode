/*
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector; using std::cout; using std::endl;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &S) {
        vector<vector<int>> vec;
        vec.push_back({});
        for(auto beg = S.cbegin(), end = S.cend();
                beg != end; ++beg) {
            for (auto iter = next(beg); ; iter++) {
                vector<int> tmp(beg, iter);
                vec.push_back(tmp);
                if (iter == end)
                    break;
            }
        }
        return vec;
    }
};

class Solution1 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end()); // 输出要求有序
        vector<vector<int> > result(1);
        for (auto elem : S) {
            result.reserve(result.size() * 2);
            auto half = result.begin() + result.size();
            copy(result.begin(), half, back_inserter(result));
            for_each(half, result.end(), [&elem](decltype(result[0]) &e){
                e.push_back(elem);
            });
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end()); // 输出要求有序
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }
private:
static void subsets(const vector<int> &S, vector<int> &path, int step,
    vector<vector<int> > &result) {
        if (step == S.size()) {
            result.push_back(path);
            return;
        }
        // 不选 S[step]
        subsets(S, path, step + 1, result);
        // 选 S[step]
        path.push_back(S[step]);
        subsets(S, path, step + 1, result);
        path.pop_back();
    }
};

int main() {
    //Solution solution;
    //vector<int> S{1, 2, 3};
    //vector<vector<int>> vec = solution.subsets(S);
    //for (auto &i : vec) {
    //    for (auto j : i)
    //        cout << j << " ";
    //    cout << endl;
    //}
    Solution2 s;
    vector<int> S{1, 2, 3};
    vector<vector<int>> vec = s.subsets(S);
    for (auto &i : vec) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
