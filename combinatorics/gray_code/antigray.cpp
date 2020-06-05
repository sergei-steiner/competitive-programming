#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<vector<int>> MirrorGray(int n) {
    if (n == 1) {
        return {{0}, {1}};
    }
    auto g = MirrorGray(n - 1);
    vector<vector<int>> ans;
    for (auto& v : g) {
       v.emplace_back(0);
       ans.emplace_back(v);
    }
    reverse(begin(g), end(g);
    for (auto v : g) {
       v.emplace_back(1);
       ans.emplace_back(v);
    }
    return ans;
}
	    
vector<int> inv(const vector<int>& v) {
    vector<int> ans;
    for (int x : v) {
        ans.push_back(1 - x);
    }
    return ans;
}

vector<vector<int>> AntiGray(int n) {
    if (n == 1) {
        return {{0}, {1}};
    }
    auto g = MirrorGray(n - 1);
    vector<vector<int>> ans;
    for (auto v : g) {
       v.emplace_back(0);
       ans.emplace_back(v);
       ans.emplace_back(inv(v));
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    
    cout << "MirrorGray:" << endl;
    for (auto v : MirrorGray(n)) {
        for (int x : v) {
	    cout << x;
	}
	cout << endl;
    }
	
    cout << "AntiGray:" << endl;
    for (auto v : AntiGray(n)) {
        for (int x : v) {
	    cout << x;
	}
	cout << endl;
    }
    return 0;
}
