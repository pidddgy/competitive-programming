// https://codeforces.com/contest/637/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define psi pair<string, int>
#define fi first
#define se second

vector<psi> ans;
vector<int> barrier;

void no() {
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, d;
    cin >> n >> m >> s >> d;

    for(int i = 1; i <= n; i++) {
        int b;
        cin >> b;

        barrier.emplace_back(b);
    }

    sort(barrier.begin(), barrier.end());

    int cur = 0, bar = 0;
    while(cur != m) {
        if(bar == n) {
            ans.emplace_back("RUN", m-cur);
            break;
        }

        if(barrier[bar] <= cur+s) {
            no();
        }

        ans.emplace_back("RUN", barrier[bar]-cur-1);
        cur = barrier[bar]-1;

        while(bar < n-1 and barrier[bar+1]-barrier[bar]-2 < s and cur+d > barrier[bar]) {
            bar++;
        }

        if(cur+d <= barrier[bar]) no();

        ans.emplace_back("JUMP", barrier[bar]+1-cur);
        cur = barrier[bar]+1;
        bar++;
    }

    for(psi x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}