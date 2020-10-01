// https://codeforces.com/contest/1239/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
const int MOD = (int)(1e9+7);

int fib[100500];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    fib[0] = fib[1] = 1;

    for(int i = 2; i <= 100000; i++) {
        fib[i] = (fib[i-1]+fib[i-2]) % MOD;
    }

    int n, m;
    cin >> n >> m;

    cout << (2*(fib[n]+fib[m]-1)) % MOD << endl;
}
