// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Junzhong Qin
// Date : 2014-12-07

/**************************************************
 * 
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
**************************************************/
#include <iostream>
using namespace std;
class Solution {
    public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int index = 0;
        for(int i = 0; i < n-1; ++i){
            if(A[i] != A[i+1]){
                A[++index] = A[i+1]; 
            }
        }    
        return index + 1;
    }
};

int main(int argc, char** argv) {
    Solution *s = new Solution();
    int A[] = {1,1,2};
    int len = s->removeDuplicates(A, 3);
    cout << "length = " << len << endl;
    return 0;
}
