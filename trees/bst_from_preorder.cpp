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

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

TreeNode* bstFromPreorder(const vector<int>& preorder, int max, int& from) {
    if (from >= preorder.size()) return nullptr;
    if (preorder[from] > max) return nullptr;
    int val = preorder[from];
    auto root = new TreeNode(val);
    ++from;
    root->left = bstFromPreorder(preorder, val, from);
    root->right = bstFromPreorder(preorder, max, from);
    return root;
}
    
TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty()) return nullptr;
    int from = 0;
    return bstFromPreorder(preorder, numeric_limits<int>::max(), from);    
}
 
int main() {
    return 0;
} 
 
