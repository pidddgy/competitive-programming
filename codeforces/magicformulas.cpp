// https://codeforces.com/contest/424/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int maxn = 1e6+5;

int p[maxn];
int cumxor[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> p[i];

    for(int i = 1; i <= maxn-3; i++) {
        cumxor[i] = (cumxor[i-1]^i);
    }

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int ans;
        if(n/i % 2 == 0) {
            ans = p[i] ^ cumxor[n%i];
        } else {
            ans = p[i] ^ cumxor[i-1] ^ cumxor[n%i];
        }

        sum ^= ans;
    }

    cout << sum << endl;
}