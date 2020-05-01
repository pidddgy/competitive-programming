// https://codeforces.com/contest/1342/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    #define int long long
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b, q;
        cin >> a >> b >> q;

        int arr[a*b];
        for(int i = 0; i < a*b; i++) { 
            int x = i+1;
            if((x%a)%b != (x%b)%a) {
                arr[i] = 1;
            } else {
                arr[i] = 0;
            }
        }

        int psa[a*b];
        psa[0] = arr[0];

        for(int i = 1; i < a*b; i++) {
            psa[i] = psa[i-1] + arr[i];
        }

        while(q--) {
            int l, r;
            cin >> l >> r;

            --l, --r;

            // watch(r)
            // watch(r/(a*b))
            // watch(r%(a*b))

            // watch(psa[a*b-1]*(r/(a*b)))
            // watch(psa[r%(a*b)])
            int rr = psa[a*b-1]*(r/(a*b)) + psa[r%(a*b)];

            int ll;
            if(l == 0) ll = 0;
            else ll = (psa[a*b-1]*((l-1)/(a*b))) + psa[(l-1)%(a*b)];

            cout << rr-ll << " ";
        }
        cout << endl;
    }
}
