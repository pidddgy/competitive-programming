// https://codeforces.com/contest/339/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxm = 1005, maxw = 15;

int m;
string s;
int path[maxm];
bool vis[maxm][maxw][maxw], have[maxw];

void dfs(int move, int diff, int last) {
    if(move == m+1) {
        cout << "YES" << endl;
        for(int i = 1; i <= m; i++) {
            cout << path[i] << " ";
        }
        cout << endl;

        exit(0);
    }

    for(int i = 1; i <= 10; i++) {
        if(i != last and i > diff and have[i]) {
            path[move] = i;
            dfs(move+1, i-diff, i);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> m;
    s = "."+s;    

    for(int i = 1; i <= 10; i++) {
        have[i] = s[i]=='1';
    }

    dfs(1, 0, -1);
    cout << "NO" << endl;
}
