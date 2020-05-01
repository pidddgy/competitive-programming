// https://codeforces.com/contest/235/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

const int maxn = 1000500;
bool prime[maxn];
bool taken[maxn];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) prime[i] = true;

    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; n-i and i < 100; i++) {
        for(int j = 0; n-j and j < 100; j++) {
            for(int k = 0; n-k and k < 100; k++) {
                ans = max(ans, lcm(n-i, lcm(n-j, n-k)));
            }
        }
    }

    cout << ans << endl;


}