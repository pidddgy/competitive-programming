// https://codeforces.com/contest/44/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
int n, a, b, c;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> c;

    int ans = 0;
    for(int i = 0; i <= b; i++) {
        for(int j = 0; j <= c; j++) {
            int sum = i + j*2;
            if(sum>n) continue;            
            int need = n-sum;
            int take = need*2;

            if(take <= a) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}