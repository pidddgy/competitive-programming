// https://codeforces.com/contest/606/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxx = 505;
const int maxs = 100500;

bool vis[maxx][maxx];
int ans[maxs];

map<char, pii> dir = {
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}},
};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x, y, x0, y0;
    cin >> x >> y >> x0 >> y0;

    string s;
    cin >> s;
    
    int slen = s.size();

    s = "."+s;
    
    int curx = x0;
    int cury = y0;

    for(int i = 1; i <= slen; i++) {
        // cerr << "on " << curx << "," << cury << endl;
        if(!vis[curx][cury]) {
            vis[curx][cury] = true;
            // cerr << "adding to " << i-1 << ", " << curx << " " << cury << " is not vis" << endl;
            ans[i-1]++;
        }

        curx += dir[s[i]].fi;
        if(curx < 1) curx = 1;
        if(curx > x) curx = x;
        
        cury += dir[s[i]].se;
        if(cury < 1) cury = 1;
        if(cury > y) cury = y;
    }
    // if(!vis[curx][cury]) {
        // vis[curx][cury] = true;
        // ans[slen-1]++;
    // }

    
    // for(int i = 0; i <= slen; i++) {
    //     cerr << ans[i] << " ";
    
    // }

    int sum = 0;
    for(int i = 0; i <= slen; i++) {
        sum += ans[i];
    }

    ans[slen] = x*y-sum;

    // cerr << endl;

    for(int i = 0; i <= slen; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}