/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 *
 *   [
 *       ["aa","b"],
 *       ["a","a","b"]
 *   ]
 *
 * DFS: 深度优先搜索 - 先找递归出口,字符串到末尾
 * xxx|xx|x perv start分别从0和1开始
 * 处理过程中出现 xxxx||xx,xxxx是回文,DFS处理xx;如果xxxx不是回文,处理xxx|x||xx
 */
#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl;
using std::string; using std::vector;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> output;
        if (s.empty()) return result;
        DFS(s, 0, 1, output, result);
        return result;
    }
private:
    void DFS(string &s, size_t prev, size_t start, vector<string> &output, vector<vector<string>> &result) {
        if (start == s.size()) {
            if (isPalidrome(s, prev, start - 1)) {
                output.push_back(s.substr(prev, start - prev));
                result.push_back(output);
                output.pop_back();
            }
            return;
        }
        DFS(s, prev, start + 1, output, result);
        if (isPalidrome(s, prev, start - 1)) {
            output.push_back(s.substr(prev, start - prev));
            DFS(s, start, start + 1, output, result);
            output.pop_back();
        }
    }
    bool isPalidrome(string &s, size_t start, size_t end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<string> output;
        vector<vector<string>> result;
        if (s.empty())
            return result;
        DFS(s, 0, output, result);
        return result;
    }
private:
    void DFS(string &s, size_t start, vector<string> &output, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                output.push_back(s.substr(start, i - start + 1));
                DFS(s, start + 1, output, result);
                output.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, size_t start, size_t end) {
        if (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int main() {
    Solution2 s;
    vector<vector<string>> result = s.partition("cbb");
    for (auto &v : result) {
        for (auto s : v)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}
