#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct TreeNode {
   int val = 0;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) 
       : val(x)
       , left(nullptr)
       , right(nullptr) 
   {
   }
};

bool isBST(TreeNode* root, int left = numeric_limits<int>::min(), int right = numeric_limits<int>::max()) {
    if (root == nullptr) return true;
    if (root->val < left) return false;
    if (root->val > right) return false;
    return isBST(root->left, left, root->val) && isBST(root->right, root->val, right);
}

int main() {

    return 0;
}
