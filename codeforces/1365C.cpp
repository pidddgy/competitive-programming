// https://codeforces.com/contest/1365/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;
int a[maxn], b[maxn], apos[maxn], bpos[maxn], shift[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        apos[a[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        bpos[b[i]] = i;
    }

    
    for(int i = 0; i < n; i++) {
        int dis = ((bpos[a[i]]-i)+n)%n;

        // cerr << "ind " << i << " has to be shifted " << dis << endl;
        shift[dis]++;
    }

    int ma = 0;
    for(int i = 0; i < n; i++) {
        ma = max(ma, shift[i]);
    }

    cout << ma << endl;
}
