#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    bool one_square(int n) {
        int root = round(sqrt(n));
        return n == root * root;
    }

    // https://en.wikipedia.org/wiki/Fermat%27s_theorem_on_sums_of_two_squares
    bool two_squares(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    ++cnt;
                }
                if (i % 4 == 3 && cnt % 2 == 1) return false;
            }
        }
        if (n > 1 && n % 4 == 3) return false;
        return true;
    }


    // https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
    bool three_squares(int n) {
        
        while (n % 4 == 0) n /= 4;
        return n % 8 < 7;
    }

    // https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem

    
    int numSquares(int n) {
        if (one_square(n)) return 1;
        if (two_squares(n)) return 2;
        if (three_squares(n)) return 3;
        return 4;
    }
};


int main() {

    return 0;
}
