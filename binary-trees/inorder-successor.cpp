#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
 
 // https://leetcode.com/problems/inorder-successor-in-bst
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* p = nullptr;
    void dfs(TreeNode* root) {
        if (root == p) return;
        if (root->val > p->val) {
            prev = root;
            dfs(root->left);
        } else {
            dfs(root->right);
        }
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        this->p = p;
        if (p == nullptr) return nullptr;
        if (p->right) {
            p = p->right;
            while (p) {
                if (p->left) {
                    p = p->left;
                } else {
                    break;
                }
            }
            return p;
        }
        dfs(root);
        return prev;
    }
};
 
int main() {

    return 0;
}
