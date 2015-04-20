/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        mysolveSudoku(board);
    }
private:
    bool mysolveSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; k++) {
                        board[i][j] = k + '1';
                        if (isvalid(i, j, board[i][j], board) && mysolveSudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(int x, int y, char c, vector<vector<char>> &board) {
        //检测行是否合法
        for (int i = 0; i < 9; i++) {
            if (i != x && board[i][y] == c)
                return false;
        }
        //检测列是否合法
        for (int j = 0; j < 9; j++) {
            if (j != y && board[x][j] == c)
                return false;
        }
        //检查3*3矩形是否合法
        for (auto row = x / 3 * 3; row < x / 3 * 3 + 3 && row < 9; row++) {
            for (auto col = y / 3 * 3; col < y / 3 * 3 + 3 && col < 9; col++) {
                if (row != x && col != y && board[row][col] == c)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char> > board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
                                  };
    s.solveSudoku(board);
    for (auto &v : board) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
