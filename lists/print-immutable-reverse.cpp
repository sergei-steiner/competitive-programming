#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/print-immutable-linked-list-in-reverse/

// O(n) time, O(sqrt(n)) space

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printRecursive(ImmutableListNode* start, ImmutableListNode* end) {
        if (start == end) return;
        printRecursive(start->getNext(), end);
        start->printValue();
    }
    void printLinkedListInReverse(ImmutableListNode* head) {
        int n = 0;
        auto cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->getNext();
        }
        int m = sqrt(n);
        cur = head;
        vector<ImmutableListNode*> a;
        for (int i = 0; i < n; ++i) {a
            if (i % m == 0) {
                a.push_back(cur);
            }
            cur = cur ->getNext();
        }
        a.push_back(nullptr);
        for (int i = a.size() - 2; i >= 0; --i) {
            printRecursive(a[i], a[i + 1]);
        }
    }
};

int main() {

    return 0;
}
