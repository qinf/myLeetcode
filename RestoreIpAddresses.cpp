/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        dfs(s, 0, 0, ip, result);
        return result;
    }
private:
    void dfs(const string &s, size_t start, int step, string ip, vector<string> &result) {
        if (step == 4 && start == s.size()) {
            //多一个.
            ip.resize(ip.size() - 1);
            result.push_back(ip);
            return;
        }

        if (s.size() - start > (4 - step) * 3)
            return;
        if (s.size() - start < (4 - step))
            return;

        int num = 0;
        for (size_t i = start; i < start + 3; i++) {
            num = num * 10 + s[i] - '0';
            if (num <= 255) {
                ip += s[i];
                dfs(s, i + 1, step + 1, ip + ".", result);
            }
            //if (num == 0) break;
        }
    }
};
int main() {
    string str("010010");
    Solution s;
    vector<string> result = s.restoreIpAddresses(str);
    for(auto &s : result){
        cout << s << endl;
    }
    return 0;
}
