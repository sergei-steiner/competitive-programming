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

    
int main() {
   string s;
   cin >> s;
   string t;
   cin >> t;
   for (int x : substr(s, t)) cout << x << " ";

    return 0;
}
