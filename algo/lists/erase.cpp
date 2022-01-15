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

// all but last

void erase(ListNode* node) {
    node->next = node->next->next;
}
int main() {

    

    return 0;
}
