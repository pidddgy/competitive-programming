#include <bits/stdc++.h>
#define fi first
#define se second
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
#define MAXN 100005
using namespace std;

ll psa[MAXN];
int main() {

    ll N, M;
    cin >> N >> M;

    cin >> psa[1];
    for(int i = 2; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    map<ll, ll> cnt;
    for(int i = 0; i <= N; i++) {
        cnt[psa[i]%M]++;
    }

    ll ans = 0;
    for(auto x: cnt) {
        ans += (x.se * (x.se-1)) / 2;
    }

    cout << ans << endl;
}
/*
2 5
5 5
 */