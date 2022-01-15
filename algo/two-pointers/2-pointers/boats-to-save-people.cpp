#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0;
        int j = n - 1;
        int sum = 0;
        while (i < j) {
             if (people[i] + people[j] <= limit) {
                 ++i;
                 --j;
             } else {
                 --j;
             }
             ++sum;
        }
        if (i == j) ++sum;
        return sum;
    }
};
    
int main() {

    return 0;
}
