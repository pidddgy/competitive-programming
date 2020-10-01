// https://codeforces.com/contest/348/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a[N+1];
    int ma = 0;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }

    int l = ma;
    int r = 1e12;
    int lastgood = 0;
    while(l <= r) {
        int m = (l+r)/2;

        int sum = 0LL;
        for(int i = 1; i <= N; i++) {
            sum += -(a[i]-m);
        }

        if(sum >= m) {
            r = m-1;
            lastgood = m;
        } else {
            l = m+1;
        }
    }

    cout << lastgood << endl;
}