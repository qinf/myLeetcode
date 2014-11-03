#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    if (s.empty())
        return true;
    int l = 0, r = s.size() - 1;
    if (l == r && tolower(s[l]) == tolower(s[r]))
        return true;
    while(l < r) {
        if (isblank(s[l]) || ispunct(s[l])) {
            l++;
            continue;
        }
        if (isblank(s[r]) || ispunct(s[r])) {
            r--;
            continue;
        }
        if (tolower(s[l]) == tolower(s[r])) {
            if(l == r || r -l == 1)
                return true;
            l++;
            r--;
        }
        else
            return false;
    }
    if (l == r)
        return true;
    return false;
}

int main() {
    string s;
    s = "A man, a plan, a canal: Panama";
    bool b = isPalindrome(s);
    cout << b << endl;
    return 0;
}
