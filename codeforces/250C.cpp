// https://codeforces.com/contest/250/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> amt;
    map<int, int> cnt;

    vector<int> a;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;

        if(a.empty()) {
            a.emplace_back(x);
        } else if(a.back() != x) {
            a.emplace_back(x);
        }
    }

    for(int i = 1; i+1 < a.size(); i++) {
        if(a[i] != a[i+1] or a[i] != a[i-1]) {
            amt[a[i]]++;
        }
        
        if(a[i-1] == a[i+1]) {
            amt[a[i]]++;
        }
    }

    amt[a[0]] += a[0] != a[1];
    amt[a[a.size()-1]] += a[a.size()-1] != a[a.size()-2];

    watch(a[a.size()-1])

    int ma = INT_MIN;
    int ans = '?';
    for(pii x: amt) {
        cerr << x.fi << " " << x.se << endl;
        if(x.se > ma) {
            ma = x.se;
            ans = x.fi;
        }
    }

    cout << ans << endl;
}