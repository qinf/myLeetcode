/* Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 *   [
 *       ["hit","hot","dot","dog","cog"],
 *       ["hit","hot","lot","log","cog"]
 *   ]
 * Note:
 *     All words have the same length.
 *     All words contain only lowercase alphabetic characters.
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using std::cout; using std::endl;
using std::map; using std::vector; using std::unordered_set;
using std::swap; using std::string; using std::reverse;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        map<string, vector<string> > father;
        unordered_set<string> curr, next;
        bool found = false;
        curr.insert(start); // 使用set是为了去重
        while (!curr.empty() && !found) {
            for (auto word : curr)
                visited.insert(word);
            for (auto word : curr) {
                string new_word(word);
                for (auto i = 0; i < new_word.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == new_word[i])
                            continue;
                        swap(c, new_word[i]);
                        if (new_word == end)
                            found = true;
                        if (visited.count(new_word) == 0 && (dict.count(new_word) > 0 || new_word == end)) {
                            next.insert(new_word);
                            father[new_word].push_back(word);
                        }
                        swap(c, new_word[i]);
                    }
                }
            }
            curr.clear();
            swap(curr, next);
        }
        vector<vector<string> > result;
        if (found) {
            vector<string> path;
            buildPath(father, path, start, end, result);
        }
        return result;
    }
private:
    void buildPath(map<string, vector<string> > &father, vector<string> path,
            const string &start, const string &word, vector<vector<string> > &result) {
        path.push_back(word);
        if (word == start) {
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        } else {
            for (auto f : father[word]) {
                buildPath(father, path, start, f, result);
            }
        }
        path.pop_back();
    }
};

int main() {
    Solution s;
    unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    vector<vector<string> > result = s.findLadders("hit", "cog", dict);
    for (auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
