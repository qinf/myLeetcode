/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using std::cout; using std::endl;
using std::string; using std::vector;

// 递归
class Solution {
public:
    vector<string> keybord {" ", "", "abc", "edf", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty())
            return result;
        string path;
        dfs(digits, 0, path, result);
        return result;
    }
private:
    void dfs(const string &digits, size_t cur, string &path, vector<string> &result) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }
        for (auto c : keybord[digits[cur] - '0']) {
            path.push_back(c);
            dfs(digits, cur + 1, path, result);
            path.pop_back();
        }
    }
};

// 迭代
class Solution2 {
public:
    vector<string> keybord {" ", "", "abc", "edf", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result(1, "");
        if (digits.empty()) {
            vector<string> s;
            return s;
        }
        for (auto d : digits) {
            auto n = result.size();
            auto m = keybord[d - '0'].size();

            result.resize(n * m);   // if no resize, segmentfault
            for (auto i = 0; i < m; i++) {
                copy(result.begin(), result.begin() + n, result.begin() + n*i);
            }
            for(auto i = 0; i < m; i++) {
                for_each(result.begin() + n*i, result.begin() + n * (i + 1), [&](string &s) {
                    s += keybord[d - '0'][i];
                });
            }
        }
        return result;
    }

};

int main() {
    Solution2 s;
    vector<string> result = s.letterCombinations("23");
    for (auto s : result)
        cout << s << endl;
    return 0;
}
