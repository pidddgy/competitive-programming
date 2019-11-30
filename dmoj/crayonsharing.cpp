#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
    #define int unsigned long long
    int N, M;
    cin >> N >> M;

    int psa[N];
    cin >> psa[0];
    for(int i = 1; i < N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    map<int, int> cnt;
    for(int i = 0; i < N; i++) {
        cnt[psa[i]%M]++;
    }

    int ans = 0;
    for(auto x: cnt) {
        ans += x.se * (x.se-1) / 2;
    }

    cout << ans << endl;


}