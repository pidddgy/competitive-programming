// https://codeforces.com/contest/1371/problem/E1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 2500;

int a[maxn];
int can[maxn];

void clear() {
    for(int i = 0; i < maxn; i++) {
        can[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }   

    vector<int> ans;

    for(int x = 0; x <= 2000; x++) {
        clear();
        bool bad = false;
        for(int i = 1; i <= n; i++) {
            int need = max(0, a[i]-x);
            if(need >= n) bad = true;

            can[need]++;
        }

        int o = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= can[i]; j++) {
                if(max(0, n-i-o)%p == 0) {
                    bad = true;
                }
                o++;
            }
        }

        if(!bad) {
            ans.emplace_back(x);
        }
    }

    cout << ans.size() << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}
