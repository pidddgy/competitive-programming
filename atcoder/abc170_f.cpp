// https://atcoder.jp/contests/abc170/tasks/abc170_f

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long
#define pld pair<ld, ld>
#define pii pair<int, int>
#define fi first
#define se second

const vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll H, W, K;
ll up(ll a, ll k = K) {
    if(a % k == 0) return a;
    return a+k - (a%k);
}

struct State {
    ll c;
    int x, y;
    int dir;

    State(ll cc, int xx, int yy, int dirr) {
        c = cc;
        x = xx;
        y = yy;
        dir = dirr;
    }
};

struct Compare {
    bool operator()(State l, State r) {
        return l.c > r.c;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0); 

    cin >> H >> W >> K;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    char a[H+5][W+5];
    vector<vector<vector<ll> > > cost (4,vector<vector<ll> >(H+3,vector <ll>(W+3,LLONG_MAX-500)));

    for(int i = 0; i < H+3; i++) {
        for(int j = 0; j < W+3; j++) {
            a[i][j] = '@';
        }
    }

    for(int i = 1; i <= H; i++) {
        string s;
        cin >> s;

        for(ll j = 0; j < s.size(); j++) {
            a[i][j+1] = s[j];
        }
    }

    set<State, vector<State>, Compare> pq;
    for(int d = 0; d < 4; d++) {
        cost[d][x1][y1] = 0;
        pq.emplace(State(0, x1, y1, d));
    }

    while(pq.size()) {
        State S = *pq.begin();
        pq.erase(pq.begin());

        int x = S.x;
        int y = S.y;
        ll c = S.c;
        int d = S.dir;

        if(c != cost[d][x][y]) continue;
        if((cost[d][x+dirs[d].fi][y+dirs[d].se] > c+1) and (a[x+dirs[d].fi][y+dirs[d].se] != '@')) {
            cost[d][x+dirs[d].fi][y+dirs[d].se] = c+1;
            pq.emplace(State(c+1, x+dirs[d].fi, y+dirs[d].se, d));
        }

        for(int di = 0; di < 4; di++) {
            ll ne = up(c);
            if(cost[di][x][y] > ne) {
                cost[di][x][y] = ne;
                pq.emplace(State(ne, x, y, di));
            }
        }
    }

    ll mi = LLONG_MAX-500;
    for(int d = 0; d < 4; d++) {
        mi = min(mi, up(cost[d][x2][y2]));
    }

    if(mi == LLONG_MAX-500) {
        cout << -1 << endl;   
    } else {
        cout << mi/K << endl;
    }
}
