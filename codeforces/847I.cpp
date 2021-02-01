// https://codeforces.com/contest/847/problem/I

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

const int maxn = 255;

const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, q, p;
char a[maxn][maxn];

// [alphabet][distance]
int cost[26][50];

bool in(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= m) {
            return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q >> p;
    for(int i = 0; i < 26; i++) {
        int cur = (i+1)*q;
        for(int j = 0; j <= 40; j++) {
            cost[i][j] = cur;
            cur /= 2;
        }
    }


    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }

    int z = 26*q;
    int maxdis = 0;
    while(z) {
        maxdis++;
        z /= 2;
    }

    assert(maxdis <= 40);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            vector<vector<int>> dis(2*maxdis+5, vector<int>(2*maxdis+5, LLONG_MAX-500));
            int shift = maxdis;
            queue<int> rQ, cQ;
            if(a[i][j] != '*') {
                rQ.push(0);
                cQ.push(0);
            }
            dis[shift][shift] = 0;

            int sum = 0;

            while(!rQ.empty()) {
                int r = rQ.front(); rQ.pop();
                int c = cQ.front(); cQ.pop();

                if(!in(i+r, j+c)) continue;

                int tmp = a[i+r][j+c]-'A';
                if(0 <= tmp and tmp <= 25) {
                    if(dis[r+shift][c+shift] <= maxdis) {
                        sum += cost[tmp][dis[r+shift][c+shift]];
                    }
                }

                for(pii d: dir) {
                    if(r+d.fi+shift < 0) continue;
                    if(c+d.se+shift < 0) continue;

                    if(dis[r+shift][c+shift]+1 < dis[r+d.fi+shift][c+d.se+shift] and 
                    dis[r+shift][c+shift]+1 <= maxdis and 
                    r+d.fi+shift < 2*maxdis+5 and 
                    c+d.se+shift < 2*maxdis+5 and
                    in(i+r+d.fi, j+c+d.se) and
                    a[i+r+d.fi][j+c+d.se] != '*') {
                        dis[r+d.fi+shift][c+d.se+shift] = dis[r+shift][c+shift]+1;
                        rQ.push(r+d.fi);
                        cQ.push(c+d.se);
                    }
                }
            }

            cerr << i << " " << j << " " << sum << endl;
            if(sum > p) ans++;
        }
    }

    cout << ans << endl;
}

/*

observation: very small amount of distance actually affects each point

tc: 250*250*50ish*50ish

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
