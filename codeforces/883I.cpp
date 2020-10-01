// https://codeforces.com/contest/883/problem/I

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second
#define int long long

const int maxn = 300500;
int n, k;

int a[maxn];

// dp[i] = valid if we have a group ending with i
bool dp[maxn];

void clear() {
    for(int i = 0; i < maxn; i++) {
        dp[i] = false;
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    int l = 0;
    int r = 1e9;
    int ans = -1;

    while(l <= r) {
        int m = (l+r)/2;
        clear();
        dp[0] = true;


        int ind = 0;

        for(int i = 1; i <= n; i++) {
            while(((!dp[ind]) or (a[i]-a[ind+1] > m)) and (ind+k < i)) {
                ind++;
            }

            if(dp[ind] and a[i]-a[ind+1] <= m and ind+k <= i) {
                dp[i] = true;
            }
        }

        if(dp[n]) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << ans << endl;
}
