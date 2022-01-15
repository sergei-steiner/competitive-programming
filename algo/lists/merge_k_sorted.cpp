#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/merge-k-sorted-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* answer = new ListNode(0);
        ListNode* result = answer;
        set<pair<int,ListNode*>> l;
        for (auto root : lists) {
            if (root) l.emplace(root->val, root);
        }
        while (true) {
            if (l.empty()) break;
            auto [f, s] = *(l.begin());
            result->next = new ListNode(f);
            l.erase(l.begin());
            if (s->next) {
                l.emplace(s->next->val, s->next);    
            }
            result = result->next;
        }
        return answer->next;
    }


};

    
int main() {

    return 0;
}
