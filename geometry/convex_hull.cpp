#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (sz(a) == 1) return;
    sort(all(a), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.pb(p1);
    down.pb(p1);
    for (int i = 1; i < sz(a); ++i) {
        if (i == sz(a) - 1 || cw(p1, a[i], p2)) {
            while (sz(up) >= 2 && !cw(up[sz(up) - 2], up[sz(up) - 1], a[i])) up.pop_back();
            up.pb(a[i]);
        }
        if (i == sz(a) - 1 || ccw(p1, a[i], p2)) {
            while (sz(down) >= 2 && !ccw(down[sz(down) - 2], down[sz(down) - 1], a[i])) down.pop_back();
            down.pb(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < sz(up); ++i) a.pb(up[i]);
    for (int i = sz(down) - 2; i > 0; --i) a.pb(down[i]);
}

int main() {

    return 0;
}
