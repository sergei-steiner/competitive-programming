/*

sometimes just don't bother
transform to vector
work with vectors
transform back
suboptimal + O(n) memory

*/

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode *> toVector(ListNode* list) {
        vector<ListNode*> ans;
        while (list) {
            ans.push_back(list);
            list = list->next;
            ans.back()->next = nullptr;
        }
        return ans;
    }
    ListNode* toList(const vector<ListNode *>& v) {
        int n = v.size();
        if (n == 0) {
            return nullptr;
        }
        auto cur = v[0];
        for (int i = 1; i < n; ++i) {
            cur->next = v[i];
            cur = v[i];
        }
        return v[0];
    } 
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto v1 = toVector(list1);
        auto v2 = toVector(list2);
        vector<ListNode*> v;
        for (int i = 0; i < a; ++i) {
            v.push_back(v1[i]);
        }
        for (auto x : v2) {
            v.push_back(x);
        }
        for (int i = b + 1; i < v1.size(); ++i) {
            v.push_back(v1[i]);
        }
        return toList(v);
    }
};
    
int main() {

    return 0;
}
