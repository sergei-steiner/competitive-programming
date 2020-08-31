#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/delete-node-in-a-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, TreeNode*> dfs(TreeNode* root, int key, TreeNode* p = nullptr) {
        if (root == nullptr) return {nullptr, p};
        if (root->val == key) {
            return {root, p};
        }
        if (root->val > key) return dfs(root->left, key, root);
        return dfs(root->right, key, root);
    }
    void unlink_and_connect(TreeNode* node, TreeNode* p, TreeNode* next) {
        if (p->left == node) {
            p->left = next;
        } else {
            p->right = next;
        }
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto dummy = new TreeNode (0);
        dummy->left = root;
        auto [node, p] = dfs(root, key, dummy);
        if (node == nullptr) return dummy->left;
        
        if (node->left != nullptr && node->right != nullptr && node->right->left != nullptr) {
            auto succ = node->right->left;
            auto succ_p = node->right;
        
            while (succ->left != nullptr) {
                succ_p = succ;
                succ = succ->left;
            }
            swap(node->val, succ->val);
            node = succ;
            p = succ_p;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            unlink_and_connect(node, p, nullptr);
            return dummy->left;
        }
        if (node->left == nullptr) {
            unlink_and_connect(node, p, node->right);
            return dummy->left;
        }
        if (node->right == nullptr) {
            unlink_and_connect(node, p, node->left);
            return dummy->left;
        }
        if (node->right->left == nullptr) {
            unlink_and_connect(node, p, node->right);
            node->right->left = node->left;
            return dummy->left;
        }
        return dummy->left;
    }
};

int main() {

    return 0;
}
