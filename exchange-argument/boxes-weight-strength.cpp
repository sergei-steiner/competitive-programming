#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct Box {
    int strength = 0;
    int weight = 0;
     
    Box(int strength, int weight)
        : strength(strength)
        , weight(weight)
    {
    }
    
    Box() = default;
};


/*
Задача про коробки. Нужно построить башню из всех данных коробок. У каждой есть
масса 𝑚𝑖 и прочность 𝑠𝑖 (какую суммарную массу можно поставить сверху).
http://opentrains.mipt.ru/zksh/files/zksh2015/lectures/mipt-2014-burunduk1.pdf
https://www.youtube.com/watch?v=7hFWrKa6yRM
*/

bool canRearrange(vector<Box>& boxes) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end(), [](Box x, Box y) { return x.strength + x.weight < y.strength + y.weight; });
    long long totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        if (totalWeight > boxes[i].strength) return false;
        totalWeight += boxes[i].weight;
    }
    return true;
}

// another comparator
bool canRearrange2(vector<Box>& boxes) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end(), [](Box x, Box y) { return min(x.strength - y.weight, y.strength) < min(y.strength - x.weight, x.strength); });
    long long totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        if (totalWeight > boxes[i].strength) return false;
        totalWeight += boxes[i].weight;
    }
    return true;
}

// n log n
int maxBoxes(vector<Box>& boxes) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end(), [](Box x, Box y) { return x.strength + x.weight < y.strength + y.weight; });
    int W = 0; // sum of weights of current tower
    auto comparator = [](Box x, Box y ) { return x.weight > y.weight; };
    multiset<Box, decltype(comparator)> currentBoxes(comparator);
    for (Box b : boxes) {
       if (b.strength >= W) {
           W += b.weight;
           currentBoxes.insert(b);
       } else {
           int Max = currentBoxes.begin()->weight;
           if (b.strength >= W - Max && b.weight < Max) {
               W -= Max;
               currentBoxes.erase(currentBoxes.begin());
               W += b.weight;
               currentBoxes.insert(b);
           }
       }
    }
    return currentBoxes.size();
}
    
int main() {
    int n;
    cin >> n;
    vector<Box> boxes;
    for (int i = 0; i < n; ++i) {
        int strength;
        int weight;
        cin >> strength >> weight;
        boxes.emplace_back(strength, weight); 
    }
    cout << canRearrange(boxes) << " " << canRearrange2(boxes) << " " << maxBoxes(boxes) << endl;
    return 0;
}
