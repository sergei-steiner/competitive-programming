#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int p = 43;
vector<unsigned int> deg = {1};

vector<unsigned int> get_hashes(const string& t) {
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
