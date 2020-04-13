#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/sort-list

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        auto current = head;
        while (current) {
            ++n;
            current = current-> next;
        }
        if (n <= 1) return head;
        current = head;
        for (int i = 0; i + 1 < n / 2; ++i) {
            current = current->next;
        }
        auto first = head;
        auto second = current->next;
        current->next = nullptr;
        first = sortList(first);
        second = sortList(second);
        ListNode* dummy = new ListNode(-1);
        current = dummy;
        while (first || second) {
            if (!first) {
                current->next = second;
                current = current->next;
                second = second->next;
                continue;
            }
            
            if (!second) {
                current->next = first;
                current = current->next;
                first = first->next;
                continue;
            }
            
            if (first->val < second->val) {
                
                current->next = first;
                current = current->next;
                first = first->next;
            } else {
                
                current->next = second;
                current = current->next;
                second = second->next;
                
            }
            
        }
        return dummy->next;
        
    }
};

int main() {
    int n;
    cin >> n;
    if (n == 0) return 0;
    int x;
    cin >> x;
    auto head = new ListNode(x);
    auto cur = head;
    
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        cur->next = new ListNode(x);
        cur = cur->next;
    } 
    head = sortList(head);
    cur = head; 
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;



    return 0;
}
