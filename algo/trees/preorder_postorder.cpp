#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct TreeNode {
   int val = 0;
   TreeNode* left = nullptr;
   TreeNode* right = nullptr;
   TreeNode(int x) 
       : val(x)
   {
   }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

TreeNode* buildTree(int i1, int j1, int i2, int j2, vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& position) {
    if (i1 > j1) return nullptr;
    int val = preorder[i1];
    TreeNode* root = new TreeNode(val);
    if (i1 + 1 <= j1) {
        int nextVal = preorder[i1 + 1];
        int pos = position[nextVal];
        int len = pos - i2 + 1;
        root->left = buildTree(i1 + 1, i1 + len, i2, pos, preorder, postorder, position);
        root->right = buildTree(i1 + len + 1, j1, pos + 1, j2, preorder, postorder, position);
    }
    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    unordered_map<int, int> position;
    int n = preorder.size();
    if (n == 0) {     
        return nullptr;
    }
    for (int i = 0; i < n; ++i) position[postorder[i]] = i;
    return buildTree(0, n - 1, 0, n - 1, preorder, postorder, position);           
}
 
int main() {
    return 0;
} 
 
