// [0,4,3,0] target=0 output:1,4
// [3, 2, 4] target=6 output:2,3
// 避免重复可以先查找再添加！
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    unordered_map<int, int> maped;
    for (int i = 0; i < numbers.size(); ++i) {
        if (maped.find(numbers[i]) == maped.end()) {
            maped[target - numbers[i]] = i;
        } else {
            result.push_back(maped[numbers[i]] + 1);
            result.push_back(i + 1);
        }
    }
   return result;
//   map<int, int> m;
//   vector<int> result;
//   for(int i=0; i<numbers.size(); i++){
//       // not found the second one
//       if (m.find(numbers[i])==m.end() ) {
//           // store the first one poisition into the second one's key
//           m[target - numbers[i]] = i;
//       }else {
//           // found the second one
//           result.push_back(m[numbers[i]]+1);
//           result.push_back(i+1);
//           break;
//       }
//   }
//   return result;
}

int main() {
    vector<int> numbers = {2, 0, 2};
    vector<int> pos = twoSum(numbers, 4);
    for (auto i : pos)
        cout << i << " ";
    cout << endl;
    return 0;
}
