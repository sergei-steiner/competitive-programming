#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/

bool isPalindrome(ListNode* head) {
    int len = 0;
    auto cur = head;
    while (cur) {
        cur = cur->next;
        ++len;
    }
    long long sum = 0;
    for (int i = 0; i < len; ++i) {
        if (len % 2 == 1 && i == len / 2) {
            head = head->next;
            continue;
        }
        srand(min(i, len - 1 - i));
        int mul = 1;
        if (i  < len / 2) mul *= -1;
        sum += (long long)rand() * mul * head->val;
        
        head = head ->next;
   }
   return sum == 0;
}
    
int main() {

    return 0;
}
