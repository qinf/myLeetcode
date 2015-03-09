#include "TreeNode.h"
#include <stack>
#include <vector>
using std::stack; using std::vector;
using std::endl; using std::cout;
vector<int> inorderTraversal(TreeNode *root) {
    TreeNode *curr = root, *prev;
    vector<int> result;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            result.push_back(curr->val);
            prev = curr;
            curr = curr->right;
        } else {
            TreeNode *node = curr->left;
            while (node->right != nullptr && node->right != curr)
                node = node->right;
            if (node->right == nullptr) {
                node->right = curr;
                curr = curr->left;
            } else {
                result.push_back(curr->val);
                node->right = nullptr;
                prev = curr;
                curr = curr->right;
            }
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
