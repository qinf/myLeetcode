/*
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 * 迭代: 1.构造增量 Solution
 *          a. 遍历S集合
 *          b. 遍历result集合，根据已有的集合构造增量(在原有的结果集上添加元素)
 *              1) 初始状态[[]]
 *                 [[]] -> [[], [1]] 取[],在此集合中添加元素1
 *              2) [[], [1]] -> [[], [1], [2]] 取[],在此集合中添加元素2
 *                 [[], [1]] -> [[], [1], [2]] -> [[], [1], [2], [1, 2]] 取[1],在此集合中添加元素2
 *
 * 递归: 1. 构造向量放
 *          a. 设置一个路径path，将path加入到result。
 *             遍历S，顺序取S中一个元素
 *          b. 将此元素放入路径，递归
 *          c. 从path中pop该元素
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::cout; using std::endl;
using std::vector;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result(1);  // 初始包含一个空的vector的vector
        size_t prev_size = 0;

        for (int i = 0; i < S.size(); i++) {    // 遍历S集合
            const size_t size = result.size();  // 保存当前result集合大小,遍历过程中会改变其大小,不能在for循环中使用size()函数
            for (int j = 0; j < size; j++) {   // 遍历result集合,构造增量
                if (i == 0 || S[i] != S[i-1] || j >= prev_size) {
                    result.push_back(result[j]);
                    result.back().push_back(S[i]);
                }
            }
            prev_size = size;
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;

        dfs(S, S.begin(), path, result);
        return result;
    }
private:
    //vector<vector<int> > dfs(vector<int> &S, vector<int>::iterator start, vector<int> &path, vector<vector<int> > &result) {
    void dfs(vector<int> &S, vector<int>::iterator start, vector<int> &path, vector<vector<int> > &result) {
        result.push_back(path);

        for(auto i = start; i != S.end(); i++) {
            if (i != start && *i == *(i-1))
                continue;
            path.push_back(*i);
            dfs(S, i + 1, path, result);
            path.pop_back();
        }
        //return result;    如果dfs有返回类型，但是没有return则会报core dump
    }
};


int main() {
    Solution2 s;
    vector<int> S{1, 2, 2};
    vector<vector<int>> result = s.subsetsWithDup(S);
    for (auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
