// https://codeforces.com/contest/1041/problem/C

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxn = 200050;

int a[maxn];
int ans[maxn];
int n, m, d;
set<pair<int, int>> S;


signed main() {
    cin >> n >> m >> d;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        S.emplace(make_pair(a[i], i));
    }

    int day = 1;
    while(!S.empty()) {
        pii p = *S.begin();
        ans[p.se] = day;
        S.erase(S.begin());

        while(true) {
            set<pii>::iterator x = S.lower_bound({p.fi+d+1, -INT_MAX});

            if(x == S.end()) {
                break;
            }

            else {
                ans[(*x).se] = day;
                p = *x;
                S.erase(x);
            }
        }

        day++;

    }

    cout << day-1 << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;





}