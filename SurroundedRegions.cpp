/*
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using std::cout; using std::endl;
using std::vector; using std::queue;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty())
            return;
        const int row = board.size();
        const int col = board[0].size();
        for (int i = 0; i < row; i++) {
            bfs(board, i, 0);
            bfs(board, i, col - 1);
        }
        for (int j = 0; j < col; j++) {
            bfs(board, 0, j);
            bfs(board, row - 1, j);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '+')
                    board[i][j] = 'O';
            }
        }
    }
private:
    void bfs(vector<vector<char>> &board, int i, int j) {
        queue<int> q;
        visit(board, i, j, q);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            int x = pos / board[0].size();
            int y = pos % board[0].size();
            visit(board, x - 1, y, q);
            visit(board, x + 1, y, q);
            visit(board, x, y - 1, q);
            visit(board, x, y + 1, q);
        }
    }
    void visit(vector<vector<char>> &board, int i, int j, queue<int> &q) {
        const int row = board.size();
        const int col = board[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O')
            return;
        board[i][j] = '+';
        q.push(i * col + j);
    }
};

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution s;
    s.solve(board);
    for (auto &v : board) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
