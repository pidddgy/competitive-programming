// https://codeforces.com/contest/1118/problem/D2   

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

const int maxn = 200500;

int n, m;
vector<int> days[maxn];
int a[maxn];

void clear() {
    for(int i = 0; i < maxn; i++) {
        days[i].clear();
    }
}

bool ok(int d) {
    clear();

    ll sum = 0;
    for(int i = 0, cur = 0; i < n; i++, cur++) {
        int tmp = a[i]-(days[cur%d].size());
        days[cur%d].push_back(max(0, tmp));
        sum += max(0, tmp);
    }

    return sum >= m;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n, greater<int>());

    int l = 1;
    int r = 2e5;
    int ans = -1;
    while(l <= r) {
        int m = (l+r)/2;

        if(ok(m)) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << ans << endl;
}
