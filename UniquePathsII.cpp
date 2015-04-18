/*
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 *
 */

#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int ret = 0;
        if (obstacleGrid.size() == 0) return ret;
        const int row = obstacleGrid.size();
        const int col = obstacleGrid[0].size();
        this->f = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        ret = dfs(obstacleGrid, row, col);
        return ret;
    }
private:
    vector<vector<int>> f;
    int dfs(const vector<vector<int>> &obstacleGrid, int row, int col) {
        if (row < 1 || col < 1) return 0;
        if (obstacleGrid[row - 1][col - 1]) return 0;
        if (row == 1 && col == 1) return 1;
        return getOrUpdate(obstacleGrid, row - 1, col) + getOrUpdate(obstacleGrid, row, col -1);
    }
    int getOrUpdate(const vector<vector<int>> &obstacleGrid, int x, int y) {
        if (f[x][y] > 0) return f[x][y];
        else return f[x][y] = dfs(obstacleGrid, x, y);
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution s;
    int ret = s.uniquePathsWithObstacles(obstacleGrid);
    cout << ret << endl;
    return 0;
}
