// https://codeforces.com/contest/741/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    
    int dis[n+1];
    vector<int> dists;
    for(int i = 1; i <= n; i++) {
        bool vis[n+1];
        for(int j = 1; j <= n; j++) vis[j] = false;

        int d = 0;
        int cur = i;
        bool found = false;
        while(!found) {
            if(a[cur] == i) {
                cerr << "dis from " << i << " to " << cur << " is " << d << endl;
                found = true;
                break;
            }

            cur = a[cur];
            d++;            
        }

        if(!found) {
            // cerr << "failed on " << i << endl;
            cout << -1 << endl;
            return 0;
        }

        dists.emplace_back(d);
    }

    int ans = 1;
    for(int x: dists) {
        watch(x)
        ans = lcm(ans, x);
    }

    cout << ans << endl;
}