/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        if (n > 0)
            dfs(n, 0, 0, path, result);
        return result;
    }
private:
    void dfs(int n, size_t l, size_t r, string path, vector<string> &result) {
        if (l == n) {
            path.append(n - r, ')');
            result.push_back(path);
            return;
        }
        dfs(n, l + 1, r, path + "(", result);
        if (r < l) {
            dfs(n, l, r + 1, path + ")", result);
        }
    }
};

int main() {
    Solution s;
    vector<string> result = s.generateParenthesis(4);
    for (auto &s : result)
        cout << s << endl;
    return 0;
}
