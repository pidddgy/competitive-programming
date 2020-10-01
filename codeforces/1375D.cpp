// https://codeforces.com/contest/1375/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        set<int> nothave;
        map<int, int> cnt;

        int a[n+1];
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        for(int i = 0; i <= 2*n; i++) {
            if(cnt[i] == 0) {
                nothave.emplace(i);
            }
        }

        int b = n-1;
        set<int> ree;
        for(int it = 1; it <= n; it++) {

            int v = *nothave.begin();
            nothave.erase(v);
        

            cerr << "using " << v << endl;
            cnt[a[min(v, b)-ree.count(n)]]--;
            ree.emplace(min(v, b)-ree.count(n));

            ans.emplace_back(min(v, b)-ree.count(n)+1);
            watch(a[2])
            cerr << "decrementing count of " << a[min(v, b)-ree.count(n)] << endl;
            watch(a[min(v, b)-ree.count(n)])
            if(cnt[a[min(v, b)-ree.count(n)]] == 0) {
                nothave.emplace(a[min(v, b)-ree.count(n)]);
            }

            a[min(v, b)-ree.count(n)] = v;

            cerr << "adding to count of " << v << endl;
            cnt[v]++;

            watch(nothave.count(0))

            cerr << endl;
        }

        for(int i = 1; i <= n; i++) {
            cerr << a[i] << " ";
        }
        cerr << endl;

        cout << ans.size() << endl;
        for(int x: ans) {
            cout << x << " ";
        }
        cout << endl;        

    }
}
