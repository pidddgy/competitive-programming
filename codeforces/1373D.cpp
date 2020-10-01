// https://codeforces.com/contest/1373/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int no = 0;
        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i&1) no += a[i];
        }

        // maximize odd instead of even(i like 1 indexing ok)

        int psa[n+1];
        psa[0] = 0;

        int peven[n+1];
        peven[0] = 0;

        for(int i = 1; i <= n; i++) {
            psa[i] = psa[i-1];

            if(i%2==0) psa[i] += a[i];
            else psa[i] -= a[i];
        }

        for(int i = 1; i <= n; i++) {
            cerr << psa[i] << " ";
        }
        cerr << endl;

        int l = -1, r = -1;
        int mi[2], miind[2];
        mi[0] = mi[1] = 0;
        miind[0] = miind[1] = 0;
        int ma = 0;

        for(int i = 1; i <= n; i++) {
            cerr << "ans for " << i << " is " << psa[i] - mi[(i%2)] << endl;
            watch(mi[(i%2)])

            if(psa[i] - mi[(i%2)] > ma) {
                l = miind[(i%2)]+1;
                r = i;
                ma = psa[i] - mi[(i%2)];
            }
            cerr << endl;

            if(psa[i] < mi[i%2]) {
                mi[i%2] = psa[i];
                miind[i%2] = i;
            }
        }

        cerr << "reversing " << l << "," << r << endl;
        reverse(a+l, a+1+r);

        for(int i = 1; i <= n; i++) {
            cerr << a[i] << " ";
        }
        cerr << endl;

        int sum = 0;
        for(int i = 1; i <= n; i += 2) {
            sum += a[i];
        }

        cout << max(no, sum) << endl;
    }
}
