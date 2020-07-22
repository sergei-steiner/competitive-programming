#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/split-bst

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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }
        if (root->val <= V) {
            auto left = root;
            auto res = splitBST(root->right, V);
            left->right = res[0];
            auto right = res[1];
            return { left, right };
        }
        auto right = root;
        auto res = splitBST(root->left, V);
        right->left = res[1];
        auto left = res[0];
        return { left, right };
    }
};
  
int main() {

    return 0;
}
