#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename Iter>
bool next_permutation_1(Iter first, Iter last) {
    auto rfirst = reverse_iterator<Iter>(last);
    auto rlast = reverse_iterator<Iter>(first);

    auto pivot = next(rfirst);
    while (pivot != rlast && prev(pivot) <= pivot) pivot++;
    if (pivot == rlast) {
        reverse(rfirst, rlast);
        return true;
    }
    auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
    swap(*change, *pivot);
    reverse(rfirst, pivot);
    return false;
}
void nextPermutation_1(vector<int> &num) {
    next_permutation_1(num.begin(), num.end());
    for (auto i : num)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> num = {6, 8, 7, 4, 3, 2};
    nextPermutation_1(num);
    return 0;
}
