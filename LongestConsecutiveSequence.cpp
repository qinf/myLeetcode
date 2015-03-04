#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int longestConsecutiveSequence(vector<int> const &num) {
    unordered_map<int, bool> maped;
    for (auto i : num)
        maped[i] = false;
    int longest = 0;
    for (auto i : num) {
        int count = 0;
        if (maped[i]) continue;
        ++count;
        maped[i] = true;
        for(int j = i + 1; maped.find(j) != maped.end(); ++j) {
            ++count;
            maped[j] = true;
        }
        for(int j = i - 1; maped.find(j) != maped.end(); --j) {
            ++count;
            maped[j] = true;
        }
        longest = longest > count ? longest : count;
    }
    return longest;
}
int main() {
    vector<int> num = {100, 4, 200, 1, 3, 2};
    int ret = longestConsecutiveSequence(num);
    cout << ret << endl;
    return 0;
}
