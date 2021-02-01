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

int n, k;
const int maxn = 150;
char a[maxn][15];
bool vis[maxn][15];
bool vis2[maxn][15];

vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void cl() {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < 15; j++) vis[i][j] = vis2[i][j] = false;
    }
}

int ok(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= 10) {
            return true;
        }
    }

    return false;
}

void gravity() {
    for(int i = 1; i <= 10; i++) {
        vector<char> v;
        for(int j = n; j >= 1; j--) {
            if(a[j][i] != '0') v.emplace_back(a[j][i]);
            a[j][i] = '0';
        }

        reverse(all(v));

        for(int j = n; j >= 1; j--) {
            if(sz(v)) {
                a[j][i] = v.back();
                v.pop_back();
            }
        }
    }
}

int bfs(bool arr[maxn][15], int sr, int sc, bool repl) {
    queue<int> rQ, cQ;

    rQ.push(sr);
    cQ.push(sc);
    arr[sr][sc] = true;

    int res =0 ;
    char chr = a[sr][sc];
    while(!rQ.empty()) {
        res++;
        int r = rQ.front(); rQ.pop();
        int c = cQ.front(); cQ.pop();

        if(repl) a[r][c] = '0';

        for(pii d: dir) {
            if(ok(r+d.fi, c+d.se) and !arr[r+d.fi][c+d.se] and a[r+d.fi][c+d.se] == chr) {
                rQ.push(r+d.fi);
                cQ.push(c+d.se);
                arr[r+d.fi][c+d.se] = true;
            }
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= 10; j++) {
            a[i][j] = s[j-1];
        }
    }

    for(int wee = 0; wee <= 1000; wee++) {
        cl();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 10; j++) {
                if(!vis[i][j] and bfs(vis, i, j, false) >= k) {
                    bfs(vis2, i, j, true);
                }
            }
        }

        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= 10; j++) {
        //         cout << a[i][j];
        //     }
        //     cout << endl;
        // }

        gravity();
        // cout << endl;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 10; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
