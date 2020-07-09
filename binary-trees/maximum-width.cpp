#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-width-of-binary-tree
// bfs!

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        unordered_map<int, int> min_val;
        unordered_map<TreeNode*, int> h;
        unordered_map<TreeNode*, int> pos;
        queue<TreeNode*> q;
        q.push(root);
        h[root] = 0;
        pos[root] = 0;
        min_val[0] = 0;
        int ans = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int height = h[node];
            int val = pos[node];
            if (min_val.count(height) == 0) min_val[height] = val;
            ans = max(ans, val - min_val[height] + 1);
            if (node->left) {
                q.push(node->left);
                h[node->left] = height + 1;
                pos[node->left] = 2 * (val - min_val[height]);
            }
            if (node->right) {
                q.push(node->right);
                h[node->right] = height + 1;
                pos[node->right] = 2 * (val - min_val[height]) + 1;
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
