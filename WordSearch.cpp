/*
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty())
            return false;
        const int row = board.size();
        const int col = board[0].size();
        this->visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                if (dfs(i, j, board, word, 0, visited))
                    return true;
            }
        }
        return false;
    }
private:
    vector<vector<bool> > visited;
    bool dfs(int row, int col, const vector<vector<char>> &board, string word, int pos,
            vector<vector<bool> > &visited) { // pos表示word中字符的位置
        if (pos == word.size())
            return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        if (visited[row][col]) return false;
        if (board[row][col] != word[pos])
            return false;

        visited[row][col] = true;
        bool ret = dfs(row + 1, col, board, word, pos + 1, visited)
                || dfs(row - 1, col, board, word, pos + 1, visited)
                || dfs(row, col + 1, board, word, pos + 1, visited)
                || dfs(row, col - 1, board, word, pos + 1, visited);
        visited[row][col] = false;
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    bool ret = s.exist(board, "ABCCED");
    cout << ret << endl;
    return 0;
}
