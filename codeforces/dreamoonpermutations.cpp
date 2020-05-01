// https://codeforces.com/contest/1330/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define fi first
#define se second

int T(int n) {
    return (n*(n+1))/2;
}

bool isTriangular(int num) { 
    int l = 1;
    int r = num;

    // int cnt = 0;
    while(l <= r) {
        // cnt++;
        // if(cnt == 5) break;
        int m = (l+r)/2;

        // watch(l)
        // watch(r)

        if(T(m) > num) {
            // cerr << "too high" << endl;
            r = m-1;
        } else if(T(m) < num) {
            // cerr << "too low" << endl;
            l = m+1;
        } else if(T(m) == num) {
            return true;
        }
    }

    return false;
} 



signed main() {
    // cout << T(200000) << endl;
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // cerr << isTriangular(15) << endl;
    // cerr << isTriangular(10) << endl;
    // cerr << isTriangular(6) << endl;
    // cerr << isTriangular(23) << endl;
    // cerr << t(3) << endl;
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        unordered_map<int, int> cnt;
        bool no = false;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;

            if(cnt[a[i]] > 2) {
                no = true;
            }
        }

        if(no) {
            cout << 0 << endl;
            continue;
        }

        int psa[n+1];
        psa[0] = 0;

        for(int i = 1; i <= n; i++) {
            psa[i] = a[i];
            psa[i] += psa[i-1];
        }

        int ans = 0;
        vector<pii> out;
        int ma = 0;
        for(int i = 1; i <= n-1; i++) {
            ma = max(ma, a[i]);
            if(isTriangular(psa[i]) and isTriangular(psa[n]-psa[i]) and (ma == i) and (T(i) == psa[i]) and (T(n-i) == psa[n]-psa[i])) {
                ans++;
                out.emplace_back(i, n-i);
            }
        }

        cout << ans << endl;
        for(pii x: out) {
            cout << x.fi << " " << x.se << endl;
        }
    }
}

/*

1
5
1 2 2 2 2

*/