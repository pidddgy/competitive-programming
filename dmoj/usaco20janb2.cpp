// https://dmoj.ca/problem/usaco20janb2

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 1005;

int a[maxn], ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N-1; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        set<int> S;
        for(int j = 1; j <= N; j++) {
            S.emplace(j);
        }
        ans[1] = i;
        S.erase(i);
        bool ok = true;
        for(int j = 2; j <= N; j++) {
            int need = a[j-1]-ans[j-1];

            if(S.count(need)) {
                ans[j] = need;
                S.erase(need);
            } else {
                ok = false;
            }
        }

        if(ok) {
            for(int j = 1; j <= N; j++) {
                cout << ans[j] << " ";
            }
            cout << endl;
            return 0;
        }

    }
}