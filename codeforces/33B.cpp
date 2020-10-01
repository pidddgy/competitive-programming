// https://codeforces.com/contest/33/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int INF = INT_MAX/2-100;

void no() {
    cout << -1 << endl;
    exit(0);
}

char out[100500];
set<pii> G[30];
int dis[30][30];

void dijk(int s) {
    for(int i = 0; i < 26; i++) {
        dis[s][i] = INF;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[s][s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()) {
        int S = pq.top().se; pq.pop();

        for(pii e: G[S]) {
            if(dis[s][S]+e.fi < dis[s][e.se]) {
                dis[s][e.se] = dis[s][S]+e.fi;
                pq.emplace(dis[s][e.se], e.se);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    if(s.size() != t.size()) no();

    int m;
    cin >> m;

    while(m--) {
        char a, b;
        int w;
        cin >> a >> b >> w;

        G[a-'a'].emplace(w, b-'a');
    }

    // watch(dijk('y'-'a', 'a'-'a'))

    for(int i = 0; i < 26; i++) {
        dijk(i);
    }

    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        int mi = INF;
        int mac = -1;
        for(int j = 0; j < 26; j++) {
            int c = dis[s[i]-'a'][j] + dis[t[i]-'a'][j];
            if(c < mi) {
                mi = c;
                mac = j;
            }
        }   

        if(mi == INF) no();

        out[i] = mac+'a';
        // cerr << "on " << s[i] << "->" << t[i] << ", cost is " << mi << endl;
        sum += mi;
    }

    cout << sum << endl;
    for(int i = 0; i < s.size(); i++) {
        cout << out[i];
    }
    cout << endl;

}
