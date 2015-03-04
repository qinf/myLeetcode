#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &num) {
    vector<vector<int>> result;
    sort(num.begin(), num.end());
    //num.erase(unique(num.begin(), num.end()), num.end());
    int n = num.size();
    for(int i = 0; i < n - 2; ++i) {
        if (i > 0 && num[i - 1] == num[i]) continue; // Output Limit Exceeded if no this line
        auto a = num[i];
        auto left = i + 1;
        auto right = n - 1;
        while (left < right) {
            if (a + num[left] + num[right] == 0) {
                result.push_back({a, num[left], num[right]});
                while (left < n && num[left] == num[left + 1]) ++left;
                while (right > 0 && num[right] == num[right - 1]) --right;
                --right;
                ++left;
            } else if (a + num[left] + num[right] > 0) {
                while(right > 0 && num[right - 1] == num[right]) --right;
                    --right;
            } else {
                while(left < n && num[left + 1] == num[left]) ++left;
                    ++left;
            }
        }
    }
    //sort(result.begin(), result.end());
    //result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main() {
    //vector<int> vec = {-1, 0, 1, 2, -1, 4};
    vector<int> vec = {1, 2};
    vector<vector<int>> result = threeSum(vec);
    for (auto &vec : result) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
