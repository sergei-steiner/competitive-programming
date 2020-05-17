#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard
// https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/636332/cpp-O(N3)-solution-with-pictures.

class Solution {
public:
    double eps = 1e-6;
    double R;

    struct Point {
        double x, y;
    };
    
    vector<Point> point;
    
    double dist(const Point& a, const Point& b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

	pair<Point, Point> getCenter(const Point& a, const Point& b) {
		Point mid;
		pair<Point, Point> res;
		mid.x = (a.x + b.x) / 2, mid.y = (a.y + b.y) / 2;
		double theta = atan2(a.y - b.y, b.x - a.x);
		double tmp = dist(a, b) / 2;
		double d = sqrt(R * R - tmp * tmp);
		res.first.x = mid.x - d * sin(theta);
		res.first.y = mid.y - d * cos(theta);
		res.second.x = mid.x + d * sin(theta);
		res.second.y = mid.y + d * cos(theta);
		return res;
	}
       
    int numPoints(vector<vector<int>>& points, int r) {
		int n = points.size();
		R = r;
		point.resize(n);
		for (int i = 0; i < n; ++i) {
			point[i].x = points[i][0];
			point[i].y = points[i][1];
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || dist(point[i], point[j]) - 2 * R > eps) continue;
				int cnt = 0;
				auto p = getCenter(point[i], point[j]);
				for (int k = 0; k < n; k++) {
					if (dist(point[k], p.first) - R < eps) 
						cnt++;
				}
				ans = max(ans, cnt);
				cnt = 0;
				for (int k = 0; k < n; k++) {
					if (dist (point[k], p.second) - R < eps) 
						cnt++;
				}
				ans = max(ans, cnt);
			}
		}
		return ans;
	}
};
    
int main() {

    return 0;
}
