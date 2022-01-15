#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct ListNode {
   int val = 0;
   ListNode* next = nullptr;
   ListNode(int x)
       : val(x)
   {
   }
};

// https://leetcode.com/problems/intersection-of-two-linked-lists/

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr) return nullptr;
    if (headB == nullptr) return nullptr;
    ListNode* endlist = nullptr; 
    auto cur1 = headA;
    auto cur2 = headB;
    while (true) {
        if (cur1 == cur2) {
            return cur1;
        }
        if (cur1->next == nullptr) {
            if (endlist && endlist != cur1) {
                return nullptr;
            }
            endlist = cur1;
            cur1 = headB;
        } else {
            cur1 = cur1->next;
        }
        if (cur2->next == nullptr) {
            if (endlist && endlist != cur2) {
                return nullptr;
            }
            endlist = cur2;
            cur2 = headA;
        } else {
            cur2 = cur2->next;
        }
     }
     return nullptr;
}

int main() {
    return 0;
}
