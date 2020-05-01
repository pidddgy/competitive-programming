// https://codeforces.com/contest/818/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define cerr if(false) cerr

const int maxn = 105;

int ans[maxn];

#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int l[m+1];
    unordered_map<int, bool> inL;
    for(int i = 1; i <= m; i++) {
        cin >> l[i];

        if(i != m)
        inL[l[i]] = true;
    }

    set<int> S;
    for(int i = 1; i <= n; i++) {
        // cerr << "emplacing " << i << endl;
        S.emplace(i);
    }

    for(int i = 1; i <= m-1; i++) {
        int need = 0;
        if(l[i+1] < l[i]) {
            need = (n-l[i]) + l[i+1];
        } else {
            need = l[i+1]-l[i];
        }
        if(need == 0) need = n;

        if(ans[l[i]] != 0) {
            cerr << "on " << i << endl;
            if(ans[l[i]] != need) {
                cout << -1 << endl; 
                return 0;
            }
            continue;
        }

        watch(need)
        for(int j = need; j <= 500; j += n) {
            cerr << "trying " << j << endl;
            if(S.count(j)) {
                ans[l[i]] = j;
                cerr << "erasing " << j << endl;
                S.erase(j);
                break;
            }
        }

        // watch(need)

    }

    for(int i = 1; i <= n; i++) {
        if(!inL[i] and ans[i] == 0) {
            cerr << "trying " << i << endl;
            if(S.size()) {
                ans[i] = *S.begin();
                S.erase(ans[i]);
            } else cerr << "oh no" << endl;
        }
    }

    int sor[n+1];
    for(int i = 1; i <= n; i++) {
        cerr << ans[i] << " ";
        sor[i] = ans[i];
    }
    cerr << endl;

    sort(sor+1, sor+n+1);
    for(int i = 1; i <= n; i++) {
        if(sor[i] != i) {
            cerr << "eee" << endl;
            cout << -1 << endl;
            return 0;
        }
    }

    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}