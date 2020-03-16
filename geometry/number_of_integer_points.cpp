#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

struct Point {
    long long X = 0;
    long long Y = 0;
};

struct Segment {
    Point Left;
    Point Right;
};

long long NumberOfIntegerPoints(const Segment& segment) {
    return gcd(abs(segment.Right.X - segment.Left.X), abs(segment.Right.Y - segment.Left.Y)) + 1;
}

class Polygon {
    int N;
    vector<Point> Points;

public:
    Polygon(const vector<Point>& points)
        : N(points.size())
        , Points(points)
    {
    }

    size_t size() const {
        return N;
    }

    const Point& operator[] (size_t i) const {
        return Points[i];
    }

    Point& operator[] (size_t i) {
        return Points[i];
    }

    long long DoubledSquare() const {
        int result = 0;
        for (size_t i = 0; i < Points.size(); ++i) {
            long long x = Points[i].X;
            long long y1 = (i > 0 ? Points[i - 1].Y : Points[N - 1].Y);
            long long y2 = (i + 1 < N ? Points[i + 1].Y : Points[0].Y);
            result += x * (y2 - y1);
        }
        return abs(result);
    }

    long long NumberOfIntegerPoints() const {
        // S = I + B / 2 - 1
        // 2 * S = 2 * I + B - 2
        // I = (2 * S - B + 2) / 2;
        long long B = 0;
        for (size_t i = 0; i < N; ++i) {
            Point left = Points[i];
            Point right = (i + 1 < N ? Points[i + 1] : Points[0]);
            Segment segment;
            segment.Left = left;
            segment.Right = right;
            B += ::NumberOfIntegerPoints(segment) - 1;
        }
        return (DoubledSquare() - B + 2) / 2;
    }
};

    
int main() {

    return 0;
}
