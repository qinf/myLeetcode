#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    unordered_map<int, pair<int, int>> maped;
    int n = num.size();
    if (n < 4) return result;
    sort(num.begin(), num.end());
    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            int left = j + 1, right = n - 1;
            int count = num[i] + num[j];
            while (left < right) {
                if (target - num[left] - num[right] != count) {
                    //maped[target - num[left] - num[right]] = {num[left], num[right]};
                    int sum = num[i] + num[j] + num[left] + num[right];
                    if (sum - target < 0) {
                        ++left;
                        //while(left < n - 1 && num[left] == num[left+1]) ++left;
                    } else if (sum - target > 0) {
                        --right;
                        //while (right > 0 && num[right] == num[right - 1]) --right;
                    }
                }
                else {
                    result.push_back({num[i], num[j], num[left], num[right]});
                    --right;
                    ++left;
                }
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main() {
    vector<int> num = {-1,2,2,-5,0,-1,4};
    vector<vector<int>> result = fourSum(num, 3);
    for (auto &vec : result) {
        for (auto i : vec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
