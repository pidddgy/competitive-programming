// https://codeforces.com/contest/638/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 105;

int N, M, K;
int a[maxn][maxn][maxn];

// Increase/decrease
vector<int> ix = {1, 0, 0};
vector<int> iy = {0, 1, 0};
vector<int> iz = {0, 0, 1};

vector<int> dx = {-1, 0, 0};
vector<int> dy = {0, -1, 0};
vector<int> dz = {0, 0, -1};

bool ok(int x, int y, int z) {
    if(1 <= x and x <= N) {
        if(1 <= y and y <= M) {
            if(1 <= z and z <= K) {
                if(a[x][y][z] == 1) {
                    return true;
                }
            }
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            string s;
            cin >> s;

            for(int k = 1; k <= K; k++) {
                a[i][j][k] = s[k-1]-'0';
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            for(int k = 1; k <= K; k++) {
                bool critical = false;
                if(!ok(i, j, k)) continue;

                for(int l = 0; l < 3; l++) {
                    for(int m = 0; m < 3; m++) {
                        // from, to
                        int fx = i+dx[l], fy = j+dy[l], fz = k+dz[l];
                        int tx = i+ix[m], ty = j+iy[m], tz = k+iz[m];

                        if(ok(fx, fy, fz) and ok(tx, ty, tz)) {
                            int ox = fx+ix[m], oy = fy+iy[m], oz = fz+iz[m];
                            if(!ok(ox, oy, oz) or (i == ox and j == oy and k == oz)) {
                                critical = true;
                            }                            
                        }

                    }
                }

                ans += critical;
            }
        }
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
