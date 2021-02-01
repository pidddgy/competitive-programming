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

const int maxn = 25;
int n;
char a[maxn][maxn];

const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok(int x, int y) {
    if(1 <= x and x <= n) {
        if(1 <= y and y <= n) {
            return true;
        }
    }

    return false;
}

int lst[maxn][maxn];

int cur = 0;

vector<int> mp[26];
int check(int i, int j, int k, int l) {
    if(i > k or j > l) return 0;
    if(!ok(i, j)) return 0;
    if(!ok(k, l)) return 0;

    cur++;
    set<char> chrs;
    for(int x = i; x <= k; x++) {
        for(int y = j; y <= l; y++) {
            if(lst[x][y] != cur) {
                if(i == 1 and j == 2 and k == 3 and l == 3) {
                    cerr << "start dfs on " << x << "," << y << endl;
                }
                int component = 0;
                queue<int> rQ, cQ;
                rQ.push(x);
                cQ.push(y);
                lst[x][y] = cur;

                while(!rQ.empty()) {
                    int r = rQ.front(); rQ.pop();
                    int c = cQ.front(); cQ.pop();
                    if(i == 1 and j == 2 and k == 3 and l == 3)
                    cerr << "visit " << r << "," << c << endl;
                    component++;

                    for(pii d: dir) {
                        if(i <= r+d.fi and r+d.fi <= k)
                        if(j <= c+d.se and c+d.se <= l)
                        if(lst[r+d.fi][c+d.se] != cur and a[r][c] == a[r+d.fi][c+d.se]) {
                            lst[r+d.fi][c+d.se] = cur;
                            rQ.push(r+d.fi);
                            cQ.push(c+d.se);
                        }
                    }

                }

                mp[a[x][y]-'A'].emplace_back(component);
            }  
        }

        if(i == 1 and j == 2 and k == 3 and l == 3) {
            // watch(sz(mp))
        }
    }

    int u = 0;
    for(int i = 0; i < 26; i++) if(sz(mp[i])) u++;
    if(u == 2) {
        int tot = 0;
        bool f = false;
        for(int i = 0; i < 26; i++) {
            if(sz(mp[i]) == 1) f = true; 
            tot += sz(mp[i]);
        }

        if(tot >= 3 and f) {
            for(int i = 0; i < 26; i++) mp[i].clear();
            return 1;
        }
    }

    for(int i = 0; i < 26; i++) mp[i].clear();
    return 0;
}

bool dp[maxn][maxn][maxn][maxn];
bool bad[maxn][maxn][maxn][maxn];



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("where.in", "r", stdin); 
    freopen("where.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= n; j++) {
            a[i][j] = s[j-1];
        }
    }

    int ans = 0;

    // x, y = lengths
    // i, j = top left corner
    for(int x = n; x >= 1; x--) {
        for(int y = n; y >= 1; y--) {
            for(int i = 1; i+x-1 <= n; i++) {
                for(int j = 1; j+y-1 <= n; j++) {
                    bool cont = false;
                    if( check(i, j, i+x-1, j+y-1)) {
                        cerr << i << "," << j << " " << i+x-1 << "," << j+y-1 << " is candidate" << endl;
                        dp[i][j][i+x-1][j+y-1] = true;
                        cont = true;
                    } 

                    bool bad = false;
                    // extend up, down, left, right
                    // up
                    if(dp[i -1][j][i+x-1][j+y-1]) {
                        bad = true;
                    }
                    // down
                    if(dp[i][j][i+x-1 + 1][j+y-1]) bad = true;
                    // left
                    if(dp[i][j-1][i+x-1][j+y-1]) bad = true;
                    // right
                    if(dp[i][j][i+x-1][j+y-1 + 1]) bad = true;

                    if(bad) {
                        dp[i][j][i+x-1][j+y-1] = true;
                        cont = false;
                    }
                    

                    if(cont) {
                        cerr << i << "," << j << " " << i+x-1 << "," << j+y-1 << endl;
                        ans++;
                    }
                }
            }
        }
    }


    cout << ans << endl;
}

/*

n^6
64 000 000

160 000

is completely inside another pcl?

dp

for i in n...1
    for j in n..1
        depend on all i+1, j or i, j+1

n^6







*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
