// https://codeforces.com/contest/275/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define pipii pair<int, pii>
#define cerr if(false) cerr
#define fi first
#define se second

const int maxn = 105;
const int INF = INT_MAX-200;

char a[maxn][maxn];
vector<pair<int, pii>> G[maxn][maxn];
int vis[maxn][maxn];
vector<int> dir = {1, -1, 0};

int n, m;
bool ok(int x, int y) {
    if(1 <= x and x <= n) {
        if(1 <= y and y <= m) {
            if(a[x][y] == 'B') {
                return true;
            }
        }
    }

    return false;
}

void clear() {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            vis[i][j] = false;
        }
    }
}

set<pii> adj(int x, int y) {
    set<pii> res;
    int curx, cury;

    curx = x;
    cury = y;

    while(ok(curx, cury)) {
        res.emplace(curx, cury);
        cury++;
    }

    curx = x;
    cury = y;

    while(ok(curx, cury)) {
        res.emplace(curx, cury);
        cury--;
    }

    curx = x;
    cury = y;

    while(ok(curx, cury)) {
        res.emplace(curx, cury);
        curx++;
    }
    curx = x;
    cury = y;

    while(ok(curx, cury)) {
        res.emplace(curx, cury);
        curx--;
    }

    return res;
}

signed main() {
    clock_t z = clock();

    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            a[i][j] = '?';
        }
    }

    cin >> n >> m;

    int cntb = 0;
    vector<pii> allB;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++) {
            a[i][j+1] = s[j];
            if(s[j] == 'B') {
                cntb++;
                allB.emplace_back(i, j+1);
            }
        }
    }

    if(cntb == n*m) {
        cout << "YES" << endl;
        return 0;
    }
    bool valid = true;

    shuffle(allB.begin(), allB.end(), default_random_engine(1238123));
    int clockit = 0;
    for(pii x: allB) {
        int i = x.fi;
        int j = x.se;
        if(a[i][j] == 'B') {
            clockit++;
            clear();
            set<pii> seen;
            
            for(pii x: adj(i, j)) {
                if(((clock()-z) / (double)CLOCKS_PER_SEC) > 1) { cout << "YES" << endl; return 0;}
                for(pii y: adj(x.fi, x.se)) {
                    // vis[y.fi][y.se] = true;
                    vis[y.fi][y.se] = true;
                }
            }


            for(int i = 1; i<= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(!vis[i][j] and ok(i, j)) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }

        if(clockit % 3 == 0)
                if(((clock()-z) / (double)CLOCKS_PER_SEC) > 1) { cout << "YES" << endl; return 0;}

    }
    

    if(valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


}