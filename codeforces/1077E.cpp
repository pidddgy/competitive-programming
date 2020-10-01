// https://codeforces.com/contest/1077/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;

int n;
int a[maxn];
multiset<int> S;
map<int, int> cnt;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(pii x: cnt) {
        S.emplace(x.se);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> rem;

        ll amt = i;
        ll sum = 0;
        while(S.lower_bound(amt) != S.end()) {
            rem.emplace_back(*S.lower_bound(amt));
            S.erase(S.lower_bound(amt));
            sum += amt;
            amt *= 2LL;
        }

        ans = max(ans, sum);
        for(int x: rem) {
            S.emplace(x);
        }
    }

    cout << ans << endl;
}
