#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/arithmetic-subarrays

// for now just solving from scratch for every query
// n log n solution is not even interesting

// O(n) with hashsets

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = a.size();
        int m = l.size();
        for (int i = 0; i < m; ++i) {
            int min_val = a[l[i]];
            int max_val = a[l[i]];
            unordered_multiset<int> b;
            for (int j = l[i]; j <= r[i]; ++j) {
                min_val = min(min_val, a[j]);
                max_val = max(max_val, a[j]);
                b.insert(a[j]);
            }
            if ((max_val - min_val) % (r[i] - l[i]) != 0) {
                ans.push_back(false);
                continue;
            }
            int d = (max_val - min_val) / (r[i] - l[i]);
            for (int j = 0; j <= r[i] - l[i]; ++j) {
                int x = min_val + d * j;
                auto it = b.find(x);
                if (it == b.end()) break;
                b.erase(it);
            }
            ans.push_back(b.empty());
        } 
        return ans;
    }
};

// O(n) solution with array

class Solution2 {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = a.size();
        int m = l.size();
        for (int i = 0; i < m; ++i) {
            int min_val = a[l[i]];
            int max_val = a[l[i]];
            for (int j = l[i]; j <= r[i]; ++j) {
                min_val = min(min_val, a[j]);
                max_val = max(max_val, a[j]);
            }
            if ((max_val - min_val) % (r[i] - l[i]) != 0) {
                ans.push_back(false);
                continue;
            }
            int d = (max_val - min_val) / (r[i] - l[i]);
            if (d == 0) {
                ans.push_back(true);
                continue;
            }
            vector<int> has(r[i] - l[i] + 1, 0);
            for (int j = l[i]; j <= r[i]; ++j) {
                int x = a[j] - min_val;
                if (x % d != 0) break;
                x /= d;
                has[x] = 1;
            }
            
            int sum = 0;
            for (int x : has) sum += x;
            ans.push_back(sum == r[i] - l[i] + 1);
        } 
        return ans;
    }
};

// O(n) solution with hashes, O(1) additional memory

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = a.size();
        int m = l.size();
        for (int i = 0; i < m; ++i) {
            int min_val = a[l[i]];
            int max_val = a[l[i]];
            long long hash1 = 1;
            unsigned long long x = 123454321;
            long long mod = 1000000007;
            for (int j = l[i]; j <= r[i]; ++j) {
                min_val = min(min_val, a[j]);
                max_val = max(max_val, a[j]);
                hash1 *= (x + a[j]);
                hash1 %= mod;
            }
            if ((max_val - min_val) % (r[i] - l[i]) != 0) {
                ans.push_back(false);
                continue;
            }
            if (max_val == min_val) {
                ans.push_back(true);
                continue;
            }
            long long hash2 = 1;
            int d = (max_val - min_val) / (r[i] - l[i]);
            for (int j = 0; j <= r[i] - l[i]; ++j) {
                hash2 *= (x + min_val + d * j);
                hash2 %= mod;
            }
            hash1 %= mod;
            hash1 += mod;
            hash1 %= mod;
            hash2 %= mod;
            hash2 += mod;
            hash2 %= mod;
            ans.push_back(hash1 == hash2);
        } 
        return ans;
    }
};

// follow-up: can we do faster???

    
int main() {

    return 0;
}
