// https://atcoder.jp/contests/abc142/tasks/abc142_d

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

set<int> factors(int n) {
    set<int> res;
    for(int i = 2; i*i <= n; i++) {
        while(n % i == 0) {
            res.emplace(i);
            n /= i;
            // watch(n)
        }
    }

    if(n != 1) {
        res.emplace(n);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    set<int> fa = factors(A), fb = factors(B);

    int ans = 0;
    for(int x: fa) {
        if(fb.count(x)) ans++;
    }

    ans++;

    cout << ans << endl;
}
