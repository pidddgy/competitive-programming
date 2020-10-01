// https://codeforces.com/contest/954/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

void no() {
    cout << "NO" << endl;
    exit(0); 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    int ma = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }

    int h = -1;

    for(int i = 2; i <= n; i++) {
        int d = abs(a[i]-a[i-1]);
        if(d == 0) no();
        if(d == 1) continue;

        if(h == -1) h = d;
        else if(h != d) {
            no();
        }
    }

    for(int i = 2; i <= n; i++) {
        int cx = (a[i]-1)/h;
        int cy = (a[i]-1)%h;

        int px = (a[i-1]-1)/h;
        int py = (a[i-1]-1)%h;

        if(!(abs(cx-px) + abs(cy-py) == 1)) {
            no();
        }
    }

    cout << "YES" << endl;
    cout << int(1e9) << " " << max(1, h) << endl;
}
