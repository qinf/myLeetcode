#include <iostream>
#include <vector>
#include <algorithm>
using std::min;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i + 1; ++j) {
                triangle[i][j] = min(triangle[i + 1][j + 1], triangle[i + 1][j]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};

int main() {
    Solution s;
    // vector<vector<int>> vec = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> vec = {{1}, {2, 3}};
    cout << s.minimumTotal(vec) << endl;
    return 0;
}
