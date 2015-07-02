/*
 * Given a string, find the length of the longest substring without repeating characters.
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> exist;
        const int N = s.size();
        int len = 0;
        int max_len = 0;
        for (int i = 0; i < N; i++) {
            if (exist.count(s[i]) == 0) {
                exist.insert({s[i], i});
                ++len;
            } else {
                //cout << exist.at(s[i]) << endl;
                i = exist.at(s[i]);
                exist.clear();
                //exist.insert({s[i], i});
                max_len = max(len, max_len);
                len = 0;
                //len = 1;
            }
        }
        for (auto m : exist)
            cout << m.first << " " << m.second << endl;
        return max(len, max_len);
    }
};

int main() {
    Solution s;
    int ret = s.lengthOfLongestSubstring("dvdf");
    cout << ret << endl;
    return 0;
}
