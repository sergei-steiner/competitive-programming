#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimize-deviation-in-array

// via multisets

class Solution {
public:
    int get_range(const multiset<int>& range) {
        auto it1 = range.begin();
        auto it2 = range.end();
        --it2;
        return *it2 - *it1;
    }
    int minimumDeviation(vector<int>& a) {
        int n = a.size();
        multiset<int> range;
        for (int x : a) {
           if (x % 2 == 1) {
               range.insert(2 * x);
           } else {
               range.insert(x);
           }
        }
        int ans = 1000000000;
        while (true) {
            ans = min(ans, get_range(range));
            auto it = range.end();
            --it;
            if (*it % 2 == 1) break;
            int x = *it;
            range.erase(it);
            range.insert(x / 2);
        }
        return ans;
    }
};

// via priority queue, a bit faster

class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        int n = a.size();
        priority_queue<int> range;
        int min_val = 1000000000;
        for (int x : a) {
            if (x % 2 == 1) {
                x *= 2;
            }
            range.push(x);
            min_val = min(min_val, x);
        }
        int ans = 1000000000;
        while (true) {
            int x = range.top();
            ans = min(ans, x - min_val);
            if (x % 2 == 1) break;
            range.pop();
            x /= 2;
            range.push(x);
            min_val = min(min_val, x);
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
