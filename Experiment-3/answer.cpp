#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    unordered_map<int,int> mp;
    int s = 0, ans = 0;
    mp[0] = -1;

    for(int i = 0; i < N; i++) {
        if(a[i] == 'P') s++;
        else s--;

        if(mp.count(s)) ans = max(ans, i - mp[s]);
        else mp[s] = i;
    }

    cout << ans;
    return 0;
}
