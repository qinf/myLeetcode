#include "TreeNode.h"
#include <stack>
#include <vector>
using std::stack; using std::vector;
using std::cout; using std::endl;
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root, *q;
    do {
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        q = nullptr;
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (p->right == q) {
                result.push_back(p->val);
                q = p;
            } else {
                s.push(p);
                p = p->right;
                break;
            }
        }
    } while (!s.empty());
    return result;
}
vector<int> postorderTraversal2(TreeNode *root) {
    vector<int> result;
    vector<TreeNode *> s;
    if (root) {
        s.push_back(root);
    }
    while (s.size() > 0) {
        TreeNode *n = s.back();
        s.pop_back();
        result.insert(result.begin(), n->val);
        if (n->left) {
            s.push_back(n->left);
        }
        if (n->right) {
            s.push_back(n->right);
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
    vector<int> vec = postorderTraversal2(&head);
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
