// https://codeforces.com/contest/1095/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
signed main() {

ios::sync_with_stdio(0);
cin.sync_with_stdio(0);
cin.tie(0);

int N;
cin >> N;

pii a[N+1];
for(int i = 1; i <= N; i++) {
    cin >> a[i].fi >> a[i].se;
}

vector<int> ans = {1};
int cnt = 1;
int cur = 1;

unordered_map<int, bool> vis;
vis[1] = true;

while(cnt < N) {
    if(((a[cur].se == a[a[cur].fi].fi) or (a[cur].se == a[a[cur].fi].se)) and (!vis[a[cur].fi])) {
        ans.emplace_back(a[cur].fi);
        vis[a[cur].fi] = true;
        cur = a[cur].fi;  
    } else if (((a[cur].fi == a[a[cur].se].fi) or (a[cur].fi == a[a[cur].se].se)) and (!vis[a[cur].se])) {
        ans.emplace_back(a[cur].se);
        vis[a[cur].se] = true;
        cur = a[cur].se;
    } else {
        assert(false);
    }
    cnt++;
}

for(int x: ans) {
    cout << x << " ";
}
cout << endl;
}