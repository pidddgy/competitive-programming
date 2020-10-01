// https://dmoj.ca/problem/pathfind

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxk = 5e5 + 500;
const int maxn = maxk;
const vector<int> dir = {-1, 0, 1};

int N, M, K;
int r[maxk], c[maxk];
set<int> blocked[maxn];
set<int> vis[maxn];

bool ok(int x, int y) {
    if(1 <= x and x <= N) {
        if(1 <= y and y <= M) {
            return true;
        }
    }

    return false;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for(int i = 1; i <= K; i++) {
        cin >> r[i] >> c[i];
        blocked[r[i]].emplace(c[i]);
    }

    string ans = "YES";
    for(int i = 1; i <= K; i++) {
        if(vis[r[i]].count(c[i])) continue;

        queue<pii> Q;
        Q.push(pii(r[i], c[i]));
        vis[r[i]].emplace(c[i]);

        set<char> chrs;
        while(!Q.empty()) {
            pii S = Q.front(); Q.pop();
            if(S.fi == 1) chrs.emplace('U');
            if(S.fi == N) chrs.emplace('D');
            if(S.se == 1) chrs.emplace('L');
            if(S.se == M) chrs.emplace('R');

            for(int x: dir) {
                for(int y: dir) {
                    if(blocked[S.fi+x].count(S.se+y) and !vis[S.fi+x].count(S.se+y)) {
                        Q.push(pii(S.fi+x, S.se+y));
                        vis[S.fi+x].emplace(S.se+y);
                    }
                }
            }   
        }

        if(chrs.count('L') and chrs.count('R')) {
            ans = "NO";
        }

        if(chrs.count('U') and chrs.count('D')) {
            ans = "NO";
        }
        
        if(chrs.count('L') and chrs.count('U')) {
            ans = "NO";
        }

        if(chrs.count('R') and chrs.count('D')) {
            ans = "NO";
        }
    }

    cout << ans << endl;
}