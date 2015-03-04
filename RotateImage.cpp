#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>> &matrix) {
    for (auto &vec : matrix) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}
vector<vector<int>> remoteImage(vector<vector<int>> &matrix) {
    print(matrix);
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }
    print(matrix);
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
    print(matrix);
    return matrix;
}
int main() {
    //vector<vector<int>> matrix = {{1,2,3},{8,9,4},{7,6,5}};
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> ret = remoteImage(matrix);
    return 0;
}
