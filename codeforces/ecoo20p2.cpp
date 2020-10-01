// https://ecoo.mcpt.ca/problem/ecoo20p2

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
// #define ll long long
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;

    while(T--) {
        ll N;
        cin >> N;

        map<string, vector<pii>> costs;
        set<string> setstr;
        for(ll i = 1; i <= N; i++) {
            ll M;
            cin >> M;

            for(ll j = 1; j <= M; j++) {
                string s;
                ll p, q;
                cin >> s >> p >> q;

                costs[s].emplace_back(p, q);
                setstr.emplace(s);
            }
        }

        for(string x: setstr) {
            sort(costs[x].begin(), costs[x].end());
        }

        ll K;
        cin >> K;

        ll ans = 0;
        for(ll i = 1; i <= K; i++) {
            string S;
            ll D;
            cin >> S >> D;

            for(pii x: costs[S]) {
                ans += min(D, x.se)*x.fi;
                // cerr << "adding" << min(D, x.se)*x.fi << endl;
                D -= x.se;
                D = max(0LL, D);
            }
        }

        cout << ans << endl;
    }
}
