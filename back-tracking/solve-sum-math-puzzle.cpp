#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/verbal-arithmetic-puzzle/

// the main idea is to solve columnwise
// not really optimized, a lot of redundant calculations
// we can actually remember carry to make it work faster
// and skip replace_all operations
// but in the end of the day it is still mostly about columnwise idea

class Solution {
public:
    int N = 7;
    bool isSolvable(vector<string>& words, string result) {
       return dfs(words, result);
    }
    bool is_char(char ch) {
        return 'A' <= ch && ch <= 'Z'; 
    }
    int chop(string& s, int len) {
        if (len > s.size()) len = s.size();
        return stoi(s.substr((int)s.size() - len, len));
    }
    bool dfs(vector<string>& words, string& result, int mask = 0) {
        for (auto& word : words) if (word[0] == '0') return false;
        if (result[0] == '0') return false;
        
        int len = N;
        for (auto& word : words) {
            for (int i = 1; i <= N; ++i) {
                if (word.size() >= i && is_char(word[word.size() - i])) {
                    len = min(len, i - 1);
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (result.size() >= i && is_char(result[result.size() - i])) {
                len = min(len, i - 1);
            }
        }
        
        if (len > 0) {
            int mod = pow(10, len);
            
            int sum = 0;
            
            for (auto& word : words) {
                sum += chop(word, len);
            }
            sum %= mod;
            
            if (sum != chop(result, len) % mod) return false;

            if (len >= N) return true;
        }
        
        ++len;
        
        char ch = 0;
        
        for (auto& word : words) {
            if (len > word.size()) continue;
            if (is_char(word[word.size() - len])) {
                ch = word[word.size() - len];
            }
        }
        if (ch == 0) ch = result[result.size() - len];
        
           
        for (int i = 0; i < 10; ++i) {
            if (mask & (1 << i)) continue;
            mask ^= (1 << i);
            char d = '0' + i;
            for (auto& word : words) {
               for (char& ch1 : word) {
                  if (ch1 == ch) ch1 = d;
               }
            }
            for (char& ch1 : result) {
                if (ch1 == ch) ch1 = d;
            }
               
            if (dfs(words, result, mask)) return true;
                
            for (auto& word : words) {
               for (char& ch1 : word) {
                  if (ch1 == d) ch1 = ch;
               }
            }
                
            for (char& ch1 : result) {
                 if (ch1 == d) ch1 = ch;
            }
            mask ^= (1 << i);

        }
        
        return false;
        
       
    }
};
    
int main() {

    return 0;
}
