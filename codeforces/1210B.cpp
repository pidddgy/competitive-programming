// https://codeforces.com/contest/1210/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

bool ok[8000];

int better(int a, int b) {
    return (a^b)&a;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;

        if(cnt[a[i]] >= 2) {
            ok[i] = true;
        }
    }

    int b[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!better(a[i], a[j]) and ok[j]) {
                ok[i] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += b[i]*ok[i];
    }

    cout << ans << endl;
}