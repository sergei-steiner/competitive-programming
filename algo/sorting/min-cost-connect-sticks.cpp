#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-cost-to-connect-sticks

class Solution {
public:
    int connectSticks(vector<int>& a) {
        multiset<int> b(begin(a), end(a));
        int ans = 0;
        while (b.size() > 1) {
            auto it1 = b.begin();
            auto it2 = b.begin();
            ++it2;
            int sum = *it1 + *it2;
            ans += sum;
            b.erase(it1);
            b.erase(it2);
            b.insert(sum);
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
