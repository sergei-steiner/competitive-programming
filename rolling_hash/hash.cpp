#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int p = 43;
vector<unsigned int> deg = {1};

// modulo prime mod
vector<int> get_hashes(const string& t, int mod) {
   int n = t.size();
   while (deg.size() <= n) {
       deg.push_back((int64)deg.back() * p % mod);
   }
   vector<int> ans;
   int s = 0; 
   for (int i = 0; i < n; ++i) {
      s += (int64)deg[i] * (t[i] - 'a' + 1); 
      s %= mod;
      ans.push_back(s);
   }
   return ans;
}


vector<int> get_hashes(const string& t) {
   int n = t.size();
   while (deg.size() <= n) {
       deg.push_back(deg.back() * p);
   }
   vector<unsigned int> ans;
   unsigned int s = 0; 
   for (int i = 0; i < n; ++i) {
      s += deg[i] * (t[i] - 'a' + 1); 
      ans.push_back(s);
   }
   return ans;
}

unsigned int get_hash(const string& t) {
   if (t.empty()) return 0; 
   return get_hashes(t).back();
}

unsigned int substr_hash(int i, int j, const vector<unsigned int>& h) {
    unsigned int ans = h[j];
    if (i > 0) ans -= h[i - 1];
    return ans * deg[h.size() - 1 - i];
}


int cmp(int l1, int r1, int l2, int r2, const string& s, const vector<unsigned int>& h) {
    int l = l1;
    int r = min(r1, l1 + r2 - l2);
    while (l < r) {
        int m = (l + r) / 2;
        if (substr_hash(l1, m, h) == substr_hash(l2, l2 + m - l, h)) {
           l = m + 1;
        } else {
           r = m;
        }
    }
    if (s[l] < s[l2 + l - l1]) return -1;
    if (s[l] > s[l2 + l - l1]) return 1;
    return 0;
}

int min_cyclic_shift(string s) {
    int n = s.size();
    s += s;
    auto h = get_hashes(s);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (cmp(ans, ans + n - 1, i, i + n - 1, s, h) == 1) ans = i; 
    }
    return ans;
}

bool is_palindrome(int i, int j, const vector<unsigned int>& h, const vector<unsigned int>& h_rev) {
    return substr_hash(i, j, h) == substr_hash(i, j, h_rev);
}

int longest_palindrome(string s) {
    auto h = get_hashes(s);
    reverse(begin(s), end(s));
    auto h_rev = get_hashes(s);
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int l = i - j + 1;
            int r = i + j - 1;
            if (l < 0) break;
            if (r >= n) break;
            if (is_palindrome(l, r, h, h_rev)) ans = max(ans, r - l + 1);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int l = i - j + 1;
            int r = i + j;
            if (l < 0) break;
            if (r >= n) break;
            if (is_palindrome(l, r, h, h_rev)) ans = max(ans, r - l + 1);
        }
    }
    return ans;
}

int different_substrings(const string& s) {
    set<pair<int, unsigned int>> a;
    int n = s.size();
    auto h = get_hashes(s);
    
    
    for (int i = 0; i < n; ++i) {
       for (int j = i; j < n; ++j) {
           a.emplace_back(j - i + 1, substr_hash(i, j, h)); 
       }
    }
    return a.size();
}

vector<int> substr(const string& s, const string& t) {
    int n = s.size();
    int m = t.size();
    if (n < m) return {} ;
    auto sh = get_hashes(s);
    auto th = get_hash(t);
    vector<int> ans; 
    for (int i = 0; i + m <= n; ++i) {
        auto subh = sh[i + m - 1];
        if (i > 0) subh -= sh[i - 1];
        if (subh == th * deg[i]) ans.push_back(i);
    }
   
   
    return ans; 
}



bool ok(const string& s, const string& t, int l) {
    int n = s.size();
    int m = t.size();
    auto h1 = get_hashes(s);
    auto h2 = get_hashes(t);
    unordered_set<unsigne int> hashes;
    for (int i = 0; i + l <= n; ++i) {
        unsigned int h = h1[i + len - 1];
        if (i > 0) h -= h1[i - 1];
        h *= deg[n - 1 - i];
        hashes.insert(h);
    }
    for (int i = 0; i + l <= m; ++i) {
        unsigned int h = h2[i + len - 1];
        if (i > 0) h -= h2[i - 1];
        h *= deg[n - 1 - i];
        if (hashes.count(h)) return true;
    }
   
    return false;
}

int common_substr(const string& s, const string& t) {
    if (s.size() < t.size()) common_substr(t, s);
    int n = s.size();
    int m = t.size();
    int l = 0;
    int r = m;
    while (l < r) {
        int mid = (l + r) / 2;
        bool ok = has_substr(s, t, mid);
        if (ok) {
           l = m;
        } else {
           r = m - 1;
        }
    }
    return l;
}

    
int main() {
   string s;
   cin >> s;
   string t;
   cin >> t;
   for (int x : substr(s, t)) cout << x << " ";

    return 0;
}
