// https://codeforces.com/contest/229/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 100500;
const int INF = LONG_MAX-100;

set<pii> G[maxn];
set<int> t[maxn];
int cost[maxn], waitTime[maxn];
int n, m;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        cost[i] = INF;
        waitTime[i] = -1;
    }

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        G[a].emplace(pii(c, b));
        G[b].emplace(pii(c, a));
    }

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        while(k--) {
            int tij; cin >> tij;

            t[i].emplace(tij);
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int icost = 0;
    while(t[1].count(icost)) icost++;

    cost[1] = icost;
    pq.push({icost, 1});

    while(pq.size()) {
        int S = pq.top().se;
        pq.pop();

        for(pii e: G[S]) {
            int c = cost[S]+e.fi;

            if(waitTime[S] != -1) c += waitTime[S];
            else {
                int cur = cost[S];
                int w = 0;
                while(t[S].count(cur)) {
                    c++;
                    w++;
                    cur++;
                }

                waitTime[S] = w;
            }

            if(c < cost[e.se]) {
                cost[e.se] = c;
                pq.push({cost[e.se], e.se});
            }
        }
    }

    if(cost[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << cost[n] << endl;
    }
}