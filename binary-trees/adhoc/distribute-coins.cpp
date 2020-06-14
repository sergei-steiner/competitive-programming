#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/distribute-coins-in-binary-tree

// calculate disbalance for each node in dp-like manner

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
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int diff1 = dfs(root->left);
        int diff2 = dfs(root->right);
        ans += abs(diff1);
        ans += abs(diff2);
        return root->val - 1 + diff1 + diff2;   
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main() {

    return 0;
}
