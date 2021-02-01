// https://codeforces.com/contest/173/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 1005;
const int shift = 1;
const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int inf = INT_MAX-500;

int n, m;
char a[maxn][maxn];
int dis[maxn][maxn][3][3];

struct State {
    int r, c, x, y;

    State(int rr, int cc, int xx, int yy) {
        r = rr;
        c = cc;
        x = xx;
        y = yy;
    }
};


struct Compare {
    bool operator()(pair<int, State> &l, pair<int, State> &r) {
        return l.fi > r.fi;
    }
};

bool ok(int A, int B) {
    if(pii(1, 0) == pii(A, B)) return true;

    if(1 <= A and A <= n) {
        if(1 <= B and B <= m) {
            return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l < 3; l++) {
                    dis[i][j][k][l] = inf;
                }
            }
        }
    }

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    priority_queue<pair<int, State>, vector<pair<int, State>>, Compare> pq;

    pq.push(make_pair(0, State(n, m, 0, -1)));
    dis[n][m][1][0] = 0;

    while(sz(pq)) {
        auto S = pq.top();
        pq.pop();

        State st = S.se;
        if(S.fi > dis[st.r][st.c][st.x+1][st.y+1]) continue;

        cerr << "currently on " << st.r << " " << st.c << " " << st.x << " " << st.y << endl;
        watch(S.fi);

        for(pii d: dir) {
            if(!ok(st.r+d.fi, st.c+d.se)) continue;

            if((a[st.r][st.c] == '#') or (d == pii(st.x, st.y))) {
                int cost = (d != pii(st.x, st.y));
                if(dis[st.r+d.fi][st.c+d.se][d.fi+1][d.se+1] > dis[st.r][st.c][st.x+1][st.y+1]+cost) {
                   dis[st.r+d.fi][st.c+d.se][d.fi+1][d.se+1] = dis[st.r][st.c][st.x+1][st.y+1]+cost;
                   pq.emplace(dis[st.r+d.fi][st.c+d.se][d.fi+1][d.se+1], State(st.r+d.fi, st.c+d.se, d.fi, d.se));
                }
            }
        }
    }

    if(dis[1][0][1][0] == inf) {
        cout << -1 << endl;
    } else {
        cout << dis[1][0][1][0] << endl;
    }
}

/*

state

[r][c][x velocity][y velocity]

1000 * 1000 * 3 * 3 
9 000 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
