// https://codeforces.com/contest/178/problem/C1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 8000;

int a[maxn];

signed main() {
    for(int i = 0; i < maxn; i++) a[i] = -1;
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int h, m, n;
    cin >> h >> m >> n;

    map<int, int> ind;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        char type;
        cin >> type;

        if(type == '+') {
            int id, hash;
            cin >> id >> hash;

            int tr = hash;
            while(a[tr] != -1) {
                tr += m;
                tr %= h;
                ans++;
            }

            a[tr] = id;
            ind[id] = tr;
        } else {
            int id;
            cin >> id;

            a[ind[id]] = -1;
        }
    }

    cout << ans << endl;
}