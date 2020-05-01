// https://codeforces.com/contest/825/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        while((k+k) < a[i]) {
            k *= 2;
            ans++;
        }

        k = max(k, a[i]);
    }

    cout << ans << endl;
}