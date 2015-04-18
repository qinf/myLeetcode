/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *
 */

#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::endl;
using std::vector; using std::string;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->columns = vector<int>(n, 0);
        this->principal_diagonal = vector<int>(2 *n, 0);
        this->counter_diagonal = vector<int>(2 * n, 0);
        vector<vector<string> > result;
        vector<int> C(n, 0);    // C[i]表示皇后列所在编号
        dfs(0, C, result);
        return result;
    }
private:
    vector<int> columns;    // 标识列是否被占用
    vector<int> principal_diagonal; //主对角线
    vector<int> counter_diagonal;   //副对角线
    void dfs(int row, vector<int> &C, vector<vector<string>> &result) {
        const int n = C.size();
        if (row == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                string s(n, '.');
                for (int j = 0; j < n; j++) {
                    if (j == C[i]) s[j] = 'Q';
                }
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }

        for (int j = 0; j < n; j++) {
            bool ok = columns[j] == 0 &&
                    principal_diagonal[row + j] == 0 && counter_diagonal[row - j + n] == 0;
            if (ok) {
                C[row] = j;
                columns[j] = principal_diagonal[row + j] = counter_diagonal[row - j + n] = 1;
                dfs(row + 1, C, result);
                // 恢复
                C[row] = 0;
                columns[j] = principal_diagonal[row + j] = counter_diagonal[row - j + n] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<string> > result;
    result = s.solveNQueens(4);
    for (auto &v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
