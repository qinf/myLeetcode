/*
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        this->column = vector<int>(n, 0);
        this->principal_diagonal = vector<int>(2 * n, 0);
        this->count_diagonal = vector<int>(2 * n, 0);
        this->count = 0;
        vector<int> C(n, 0);
        dfs(0, C);
        return count;
    }
private:
    int count;
    vector<int> column;
    vector<int> principal_diagonal;
    vector<int> count_diagonal;
    void dfs(int row, vector<int> &C) {
        const int N = C.size();
        if (row == N) {
            ++count;
            return;
        }
        for (int j = 0; j < N; j++) {
            bool ok = column[j] == 0 && principal_diagonal[row + j] == 0 &&
                    count_diagonal[row - j + N] == 0;
            if (ok) {
                C[row] = j;
                column[j] = principal_diagonal[row + j] = count_diagonal[row - j + N] = 1;
                dfs(row + 1, C);
                column[j] = principal_diagonal[row + j] = count_diagonal[row - j + N] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    int n = s.totalNQueens(2);
    cout << n << endl;
    return 0;
}
