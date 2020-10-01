// https://codeforces.com/contest/1082/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long long

const int maxn = 100500, maxm = 100500;

int n, m;

vector<int> a[maxm];

bool bysz(vector<int> &l, vector<int> &r) {
    return l.size()<r.size();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        a[i].emplace_back(0);
    }

    for(int i = 1; i <= n; i++) {
        int s, r;
        cin >> s >> r;

        a[s].emplace_back(r);
    }

    set<int> S;
    for(int i = 1; i <= m; i++) {
        if(a[i].empty()) continue;
        S.emplace(i);
        sort(a[i].begin()+1, a[i].end(), greater<int>());
        assert(a[i][0] == 0);
        for(int j = 1; j < a[i].size(); j++) {
            a[i][j] += a[i][j-1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        set<int> er;
        int sum = 0;
        for(int j: S) {
            if((a[j].size()-1) < i or a[j][i] < 0) {
                er.emplace(j);
                continue;
            }

            sum += a[j][i];
        }

        for(int x: er) {
            S.erase(x);
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;
}