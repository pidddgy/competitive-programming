// https://codeforces.com/contest/1077/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

const int maxn = 105;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 2; i+1 <= N; i++) {
        if(a[i] == 0 and a[i-1] == 1 and a[i+1] == 1) {
            a[i+1] = 0;
            ans++;
        }
    }

    cout << ans << endl;
}
