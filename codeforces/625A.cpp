// https://codeforces.com/contest/625/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
int n, a, b, c;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> c;

    int ans1 = n/a;

    int ans2 = 0;

    if(n >= b) {
        n -= b;
        ans2 += n/(b-c);
        n -= (n/(b-c))*(b-c);
        n += b;

        while(n >= b) {
            ans2++;
            n -= b;
            n += c;
        }

        ans2 += n/a;
    }

    // watch(ans2)

    cout << max(ans1, ans2) << endl;
}
