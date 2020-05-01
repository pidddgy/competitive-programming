// https://codeforces.com/contest/1333/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long long
const int maxn = 200500;

int a[maxn];
int psa[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        psa[i] = a[i] + psa[i-1];
    }

    for(int i = 1; i <= n; i++) {
        cerr << psa[i] << " ";
    }
    cerr << endl;

    set<int> S;
    S.emplace(0);

    int ans = 0;
    int r = 0;
    for(int l = 1; l <= n; l++) {
        while(r <= n-1 and !S.count(psa[r+1])) {
            S.emplace(psa[r+1]);
            r++;
        }
        cerr << "using " << l << "," << r << endl;
        ans += (r-l)+1;
        S.erase(psa[l-1]);
    }

    cout << ans << endl;


}