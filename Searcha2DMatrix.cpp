/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 *
 */

#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();
        int first = 0, last = m * n;

        while (first != last) {
            auto mid = first + (last - first) / 2;
            auto value = matrix[mid / n][mid % n];
            if (target == value)
                return true;
            else if (target > value)
                first = ++mid;
            else
                last = mid;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> vec =  {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    //bool flag = solution.searchMatrix(vector<vector<int>> {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 3);
    bool flag = solution.searchMatrix(vec, 3);
    std::cout << flag << std::endl;
    return 0;
}
