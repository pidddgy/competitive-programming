// https://codeforces.com/contest/1373/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 1000500;
int cnt[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        s = "."+s;

        int need = 0;
        int cur = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '-') {
                cur++;
            } else {
                cur--;
            }

            cnt[i] = max(cnt[i-1], cur);
        }

        int ans = 0;
        int last = 0;
        cur = cnt[1];

        for(int i = 1; i <= n; i++) {
            if(cnt[i] != cur) {
                last = cur;
                cur = cnt[i];
            }
            
            if(i == n) {
                ans += (i*max(1LL, cur-last));
            }
            
            if((cnt[i] != cnt[i-1])) {
                ans += (i*(cur-last));
                continue;
            }
        }

        cout << ans << endl;

        for(int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
    }
}
