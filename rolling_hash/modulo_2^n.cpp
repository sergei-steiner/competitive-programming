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
    
int main() {

    return 0;
}
