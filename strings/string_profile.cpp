#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// example of simple problem

class Solution {
public:
    vector<int> buildProfile(const string& s) {
        vector<int> result(26, 0);
        for (char ch : s) ++result[ch - 'a'];
        return result;
    }
    
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransomNoteProfile = buildProfile(ransomNote);
        vector<int> magazineProfile = buildProfile(magazine);
        for (int i = 0; i < 26; ++i) {
            if (ransomNoteProfile[i] > magazineProfile[i]) return false;
        }
        return true;
    }
};

