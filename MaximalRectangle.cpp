#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if (m == 0)
            return 0;
        const int n = matrix[0].size();
        vector<int> vec(n, 0);
        vector<vector<int> > height(m, vec);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    height[i][j] = 0;
                } else {
                    height[i][j] = (i == 0 ? 1 : height[i - 1][j] + 1);
                }
            }
        }
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            int area = myMaximalRectangle(height[i]);
            if (area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
    int myMaximalRectangle(vector<int> vec) {
        stack<int> height_stack;
        int i = 0;
        int maxArea = 0;
        for (; i < vec.size(); ) {
            if (height_stack.empty() || vec[i] >= vec[height_stack.top()]) {
                height_stack.push(i++);
            } else {
                int t = height_stack.top();
                height_stack.pop();
                maxArea = max(maxArea, vec[t] * (height_stack.empty() ? i : i - height_stack.top() - 1));
            }
        }
        while (!height_stack.empty()) {
            int tp = height_stack.top();
            // cout << "i = " << i << endl;
            // cout << "maxArea = " << maxArea << endl;
            height_stack.pop();
            maxArea = max(maxArea, vec[tp] * (height_stack.empty() ? i : i - height_stack.top() - 1));
        }
        return maxArea;
    }
};

int main() {
    vector<vector<char>> vec = {{'0', '0', '1', '0'}, {'0', '0', '0', '1'}, {'0', '1', '1', '1'}, {'0', '0', '1', '1'}};
    // vector<vector<char>> vec = {{'1', '1', '0'}};
    Solution s;
    cout << s.maximalRectangle(vec) << endl;
    return 0;
}
