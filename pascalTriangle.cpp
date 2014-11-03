// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : Junzhong Qin
// Date   : 2014-11-03

/****************************************
 *
 * ven numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *     [1],
 *    [1,1],
 *   [1,2,1],
 *  [1,3,3,1],
 * [1,4,6,4,1]
 * ]
 *
 ****************************************/
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > pascalTriangle;
    for(int i = 0; i < numRows; i++) {
        vector<int> vec;
        if (i == 0) {
            vec.push_back(1);
            pascalTriangle.push_back(vec);
        }
        else {
            vec.push_back(1);
            for(int j = 0; j < pascalTriangle[i-1].size() - 1; j++) {
                vec.push_back(pascalTriangle[i-1][j] + pascalTriangle[i-1][j+1]);
            }
            vec.push_back(1);
            pascalTriangle.push_back(vec);
        }
    }
    return pascalTriangle;
}

void printPasalTriangle(vector<vector<int> > v) {
    cout << "[" << endl;
    for (int i=0; i<v.size(); i++) {
        for (int j=v.size()-i; j>0; j--) {
            cout << " ";
        }
        cout << "[";
        for (int k = 0; k < v[i].size(); k++) {
            cout << v[i][k];
            if (k != v[i].size()-1)
                cout << ",";
        }
        cout << "]";
        cout << endl;
    }
    cout << "]" << endl;
}

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    printPasalTriangle(generate(n));
    return 0;
}
