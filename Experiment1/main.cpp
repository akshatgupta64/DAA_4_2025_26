#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
using namespace std :: chrono;
int globalCount = 0;
int globalDepth = 0;
void complexRec(int n , int depth) {
    globalDepth = max(globalDepth , depth);
    globalCount++;
    if (n <= 2) {
        return;
    }


    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
        }
        p >>= 1;
    }


    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
    }


    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
    } else {
        reverse(small.begin(), small.end());
    }


    complexRec(n / 2 , depth + 1);
    complexRec(n / 2 , depth + 1);
    complexRec(n / 2 , depth + 1);
}
int main() {
    auto start = high_resolution_clock::now();
    int n; cin >> n;
    complexRec(n , 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "ms" << "\n";
    cout << globalCount << "\n";
    cout << globalDepth;
}
// Recurrence relation : 3T(n/2) + nlogn + n + n/2
// Overall TC : n ^ log(3 , 2)