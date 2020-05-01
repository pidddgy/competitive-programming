// https://codeforces.com/contest/645/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define cerr if(false) cerr
#define endl '\n'

string s;
int n, k;
int incr(int i) {
    i++;
    while(i < n and s[i] == '1') {
        i++;
    }

    return i;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cin >> s;

    s = "."+s;
    watch(s)

    int l = incr(0);

    int m = l;
    int r = l;

    for(int i = 1; i <= k; i++) r = incr(r);

    int ans = INT_MAX;
    while(r <= n) {
        while(max(m-l, r-m) > max(incr(m)-l, r-incr(m))) {
            m = incr(m);
        }

        watch(l)
        watch(m)
        watch(r)
        cerr << endl;
        ans = min(ans, max(m-l, r-m));
        l = incr(l);
        r = incr(r);

        if(s[l] == '1' or s[r] == '1') break;
    }

    cout << ans << endl;

    

}