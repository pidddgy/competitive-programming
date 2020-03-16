// https://codeforces.com/contest/1129/problem/A2

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    int out[n+1];
    int mi[n+1];

    for(int i = 1; i <= n; i++) {
        out[i] = 0;
        mi[i] = INT_MAX;
    }

    int dis[n+1][n+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == i) dis[i][j] = 0;
            else if(j > i) dis[i][j] = j-i;
            else if(i > j) dis[i][j] = n-(i-j); 

            cerr << "dist from " << i << " to " << j << " is " << dis[i][j] << endl;
        }
    }

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        out[a]++;
        mi[a] = min(mi[a], dis[a][b]);
    }

    watch(mi[2])

    for(int st = 1; st <= n; st++) {
        int ans = 0;
        cerr << "currently on " << st << endl;
        for(int i = 1; i <= n; i++) {
            if(out[i]) {
                cerr << "considering " << out[i] << endl;
                cerr << "tot time is " << dis[st][i] + (out[i]-1)*n + mi[i] << endl;
                watch(dis[st][i])
                watch((out[i]-1)*n)
                watch(mi[i])
                ans = max(ans, dis[st][i] + (out[i]-1)*n + mi[i]);
            }
        }

        cout << ans << " ";
        cerr << endl;
    }
    cout << endl;
}