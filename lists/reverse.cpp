#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x)
       : val(x)
       , next(nullptr)
   {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next = head->next;
    while (true) {
        cur->next = prev;
        prev = cur;
        if (next == nullptr) return cur;
        cur = next;
        next = next->next;
    }
}

ListNode* reverseListRecursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* reversed = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr; 
    return reversed;
}

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
    head = reverseList(head);
    cur = head; 
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
   
    head = reverseListRecursive(head);
    cur = head; 
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
