#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://en.wikipedia.org/wiki/Happy_number

int sum_digits_squares(int n, int b = 10) {
   int ans = 0;
   while (n) {
      ans += (n % b) * (n % b);
      n /= b;
   }
   return ans;
}



// https://en.wikipedia.org/wiki/Happy_number#10-happy_numbers

bool isHappy(int n, int b = 10) {
    if (b == 10) return isHappy10(n);
    if (b == 2 || b == 4) return true; // the only happy bases <= 3 * 10^8
    int x = n;
    int y = n;
    while (true) {
        x = sum_digits_squares(x);
        y = sum_digits_squares(sum_digits_squares(y));
        if (y == 1) return true;
        if (x == y) return false; 
    }
    return true;
}

// b = 10
// https://leetcode.com/problems/happy-number/
// https://en.wikipedia.org/wiki/Happy_number#10-happy_numbers

bool isHappy10(int n) {
   while (true) {
       if (n == 1) return true;
       if (n == 4) return false;
       n = sum_digits_squares(n);
   }
   return false;
}
 
int main() {

    return 0;
}
