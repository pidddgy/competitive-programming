// https://codeforces.com/contest/476/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

int trng(int n) {
    return (n*(n+1))/2;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int first = 0;
    for(int i = 1; i <= 1e8; i++) {
        if(i%b == 0) continue;

        cerr << (i/b) / (i%b) << endl;
        if(1 <= (i/b) / (i%b) and (i/b) / (i%b) <= a) {
            first++;
        }

        if(i > 10) break;
    }

    watch(first)

    int ans = 0;
    for(int i = 1; i < b; i++) {
        ans += i*first;
    }

    cout << ans << endl;
}