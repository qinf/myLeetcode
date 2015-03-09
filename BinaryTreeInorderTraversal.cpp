#include "TreeNode.h"
#include <stack>
#include <vector>
using std::stack; using std::vector;
using std::endl; using std::cout;
vector<int> inorderTraversal(TreeNode *root) {
    TreeNode *p = root;
    vector<int> result;
    stack<TreeNode *> st;
    while (!st.empty() || p != nullptr) {
        if (p) {
            st.push(p);
            p = p->left;
        } else {
            p = st.top();
            st.pop();
            result.push_back(p->val);
            p = p->right;
        }
    }
    return result;
}
int main() {
    TreeNode head(1);
    TreeNode l1(2);
    TreeNode l2(3);
    head.left = &l1;
    head.right = &l2;
    vector<int> vec = inorderTraversal(&head);
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
