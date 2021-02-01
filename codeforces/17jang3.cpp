#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const int maxn = 25;
// URDL
const vector<pii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int mod(int num) {
    return (num+8)%4;
}
int n;
bool a[maxn][maxn];


bool ok(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= n) {
            if(!a[r][c])
            return true;
        }
    }

    return false;
}

int dis[maxn][maxn][maxn][maxn][5][5];

struct State {
    int r1, c1, r2, c2, d1, d2;
    State(int R1, int C1, int R2, int C2, int D1, int D2) {
        r1 = R1;
        c1 = C1;
        r2 = R2;
        c2 = C2;
        d1 = D1;
        d2 = D2;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    cin >> n;
    for(int i = n; i >= 1; i--) {
        string s;
        cin >> s;

        for(int j = 1; j <= n; j++) {
            if(s[j-1] == 'H') a[i][j] = true;
        }
    }
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            for(int k = 0; k < maxn; k++) {
                for(int l = 0; l < maxn; l++) {
                    for(int x = 0; x < 5; x++) {
                        for(int y = 0; y < 5; y++) {
                            dis[i][j][k][l][x][y] = 1e18;
                        }
                    }
                }
            }
        }
    }

    queue<State> Q;
    dis[1][1][1][1][0][1] = 0;

    Q.push(State(1, 1, 1, 1, 0, 1));
    while(!Q.empty()) {
        State S = Q.front(); Q.pop();

        int dcur = dis[S.r1][S.c1][S.r2][S.c2][S.d1][S.d2];
        cerr << S.r1 << " " << S.c1 << endl;
        cerr << S.r2 << " " << S.c2 << endl;


        // forward 
        State nxt = S;
        if(pii(nxt.r1, nxt.c1) != pii(n, n)) {
            nxt.r1 += dir[nxt.d1].fi;
            nxt.c1 += dir[nxt.d1].se;
            if(!ok(nxt.r1, nxt.c1)) {
                nxt.r1 -= dir[nxt.d1].fi;
                nxt.c1 -= dir[nxt.d1].se;
            }
        }
        
        cerr << "forward ends up in " << nxt.r1 << " " << nxt.c1 << endl;

        if(pii(nxt.r2, nxt.c2) != pii(n, n)) {
            nxt.r2 += dir[nxt.d2].fi;
            nxt.c2 += dir[nxt.d2].se;
            if(!ok(nxt.r2, nxt.c2)) {
                nxt.r2 -= dir[nxt.d2].fi;
                nxt.c2 -= dir[nxt.d2].se;
            }
        }
        cerr << "forward ends up in " << nxt.r2 << " " << nxt.c2 << endl;

        int dnxt = dis[nxt.r1][nxt.c1][nxt.r2][nxt.c2][nxt.d1][nxt.d2];
        if(dnxt > dcur+1) {
            Q.push(nxt);
            dis[nxt.r1][nxt.c1][nxt.r2][nxt.c2][nxt.d1][nxt.d2] = dcur+1;
        }

        // turn left
        nxt = S;

        nxt.d1--;
        nxt.d1 = mod(nxt.d1);

        nxt.d2--;
        nxt.d2 = mod(nxt.d2);

        dnxt = dis[nxt.r1][nxt.c1][nxt.r2][nxt.c2][nxt.d1][nxt.d2];
        if(dnxt > dcur+1) {
            Q.push(nxt);
            dis[nxt.r1][nxt.c1][nxt.r2][nxt.c2][nxt.d1][nxt.d2] = dcur+1;
        }

        // other way
        nxt = S;

        nxt.d1++;
        nxt.d1 = mod(nxt.d1);

        nxt.d2++;
        nxt.d2 = mod(nxt.d2);

        dnxt = dis[nxt.r1][nxt.c1][nxt.r2][nxt.c2][nxt.d1][nxt.d2];
        if(dnxt > dcur+1) {
            Q.push(nxt);
            dis[nxt.r1][nxt.c1][nxt.r2][nxt.c2][nxt.d1][nxt.d2] = dcur+1;
        }
    }
    

    int ans = 1e18;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            ans = min(ans, dis[n][n][n][n][i][j]);
        }
    }

    cout << ans << endl;
}

/*

dp[i][j][i][j][dir1][dir2]

2 560 000

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
