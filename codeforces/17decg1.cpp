#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 100500;

int n, d;

// bessie, elsie
set<pair<pii, int>> s1, s2;
int dis[2*maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);

    for(int i = 0; i < 2*maxn; i++) dis[i] = 1e18;

    cin >> n >> d;

    queue<pair<pii, int>> Q;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        if(y == 0) {
            Q.push({pii(y, x), i});
            dis[i] = 1;
        } else {
            s1.emplace(pii(y, x), i);
        }
    }

    for(int i = n+1; i <= 2*n; i++) {
        int x, y;
        cin >> x >> y;

        if(x == 0) {
            Q.push({pii(x, y), i});
            dis[i] = 1;
        } else {
            s2.emplace(pii(x, y), i);
        }
    }

    while(!Q.empty()) {
        auto S = Q.front(); Q.pop();

        // s.fi is how other sees
        // s.se is how we see
        
        cerr << "currently on " << S.fi.fi << " " << S.fi.se << " " << S.se << endl;
        if(S.se <= n) {
            // grab from s2
            pair<pii, int> p = {{S.fi.se-d, -1e18}, -1e18};

            cerr << "looking for " << p.fi.fi << " " << p.fi.se << " " << p.se << endl;
            cerr << "must be greater than " << S.fi.se << endl;
            watch(S.se)

            for(;;) {
                if(s2.empty()) break;
                auto ptr = s2.lower_bound(p);
                if(ptr == s2.end()) break;

                pair<pii, int> val = *ptr;

                if(val.fi.fi > S.fi.se) break;

                int to = val.se;

                if(dis[to] > dis[S.se]+1) {
                    Q.push(val);
                    dis[to] = dis[S.se]+1;
                }

                s2.erase(ptr);
            }
        } else {
            // grab from s1
            pair<pii, int> p = {{S.fi.se-d, -1e18}, -1e18};


            for(;;) {
                if(s1.empty()) break;
                auto ptr = s1.lower_bound(p);
                if(ptr == s1.end()) break;

                pair<pii, int> val = *ptr;

                if(val.fi.fi > S.fi.se) break;

                int to = val.se;

                if(dis[to] > dis[S.se]+1) {
                    Q.push(val);
                    dis[to] = dis[S.se]+1;
                }

                s1.erase(ptr);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dis[i] == 1e18) cout << -1 << endl;
        else cout << dis[i] << endl;
    }
}

/*

if cows already has a pie of tastiness 0, do they end right away?

multisource bfs on each index, starting from 0s and go outwards

have two sets
set<pair<pii, int>> s1, s2
sets are based on how the other person perceives

we just used a pie we see as tastiness x. let o = other. the other person must have used a pie that we see as >= x-d tastiness and <= x tastiness.

get lower_bound of x-d
check if it is <= x

if valid and dis less go
otherwise stop



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
