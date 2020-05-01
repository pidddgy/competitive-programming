// https://codeforces.com/contest/1025/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define watch(x) cerr << (#x) << " is " << (x) << endl;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; 
    cin >> N;

    pii a[N+1];
    int ans = 0;

    for(int i = 1; i <= N; i++) {
        cin >> a[i].fi >> a[i].se;
        ans = gcd(ans, a[i].fi*a[i].se);
    }


    for(int i = 1; i <= N; i++) {
        int f = gcd(ans, a[i].fi);
        int s = gcd(ans, a[i].se);

        if(f == 1) {
            ans = s;
        } else {
            ans = f;
        }
    }

    if(ans == 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    
}