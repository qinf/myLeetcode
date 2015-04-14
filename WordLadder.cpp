/*
 * Word Ladder
 * Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 *
 */

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using std::cout; using std::endl;
using std::string; using std::unordered_set;
using std::unordered_map; using std::swap;
using std::queue;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord.empty() || endWord.empty())
            return 0;
        if (beginWord.size() != endWord.size())
            return 0;
        queue<string> curr, next;
        unordered_set<string> visited;
        unordered_map<string, string> father;
        int level = 0;
        bool found = false;

        curr.push(beginWord);
        while (!curr.empty() && !found) {
            ++level;
            while (!curr.empty() && !found) {
                const string str(curr.front());
                curr.pop();

                for (size_t i = 0; i < str.size(); i++) {
                    string new_word(str);
                    for(char c = 'a'; c <= 'z'; c++) {
                        if (c == new_word[i]) continue;
                        swap(c, new_word[i]);
                        if (new_word == endWord) {
                            found = true;
                            //visited.insert(new_word);
                            father[new_word] = str;
                            break;
                        }

                        if (wordDict.count(new_word) > 0 && !visited.count(new_word)) {
                            visited.insert(new_word);
                            father[new_word] = str;
                            next.push(new_word);
                        }
                        swap(c, new_word[i]);
                    }
                }
            }
            swap(curr, next);
        }
        if (found)
            return level + 1;
        else
            return 0;
    }
};

int main() {
    Solution s;
    unordered_set<string> wordDict = {"hot", "dot", "dog", "lot", "log"};
    auto i = s.ladderLength("hit", "cog", wordDict);
    cout << i << endl;
    return 0;
}
