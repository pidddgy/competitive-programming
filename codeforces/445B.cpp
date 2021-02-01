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

const int maxn = 100500;

int n, k;

int tind = 1;
int nxt[maxn][26];

// can current player force a win/lose from this position?
bool win[maxn];
bool lose[maxn];

bool vis[maxn];

void cl() {
    for(int i = 0; i < maxn; i++) {
        vis[i] = false;
    }
}

// fill out win[]
void dfs(int v) {
    for(int i = 0; i < 26; i++) {
        int to = nxt[v][i];

        if(to == -1) continue;

        if(!vis[to]) dfs(to);
        if(!win[to]) win[v] = true;
    }
    vis[v] = true;
}

// fill out lose[]
void dfs2(int v) {
    bool leaf = true;
    for(int i = 0; i < 26; i++) {
        int to = nxt[v][i];
        if(to == -1) continue;

        leaf = false;

        if(!vis[to]) dfs2(to);

        if(!lose[to]) {
            char chr = i+'a';
            cerr << v << " can force a lose by going to " << chr << endl;
            lose[v] = true;
        }
    }
    vis[v] = true;
    if(leaf) lose[v] = true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < 26; j++) {
            nxt[i][j] = -1;
        }
    }

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        int cur = 1;
        string s;
        cin >> s;
        for(char x: s) {
            int to = nxt[cur][x-'a'];

            if(to == -1) to = ++tind;

            nxt[cur][x-'a'] = to;
            cur = to;
        }
    }

    dfs(1);
    cl();
    dfs2(1);

    vector<string> ans = {"First", "Second"};

    cerr << win[1] << " " << lose[1] << endl;
    if(win[1]) {
        if(lose[1]) {
            cout << ans[0] << endl;
        } else {
            cout << ans[(k%2)^1] << endl;
        }
    } else {
        cout << ans[1] << endl;
    }


}

/*

we want to be able to lose over and over

check if first player can make himself win

if first player can only make himself win answer = parity
    - if either player wanted to change the parity, the other player could block it

if first player can make himself win or lose anwer = player 1
    - player 1 keeps making himself lose, then wins on the last one

if first player cannot decide outcome answer = player 2
if first player can only make himself lose answer = player 2
    - player 2 keeps making player 1 lose, then wins on last



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
