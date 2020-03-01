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

// b = 10

// https://en.wikipedia.org/wiki/Happy_number#10-happy_numbers

// https://leetcode.com/problems/happy-number/

bool isHappy(int n) {
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
