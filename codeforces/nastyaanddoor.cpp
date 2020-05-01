// https://codeforces.com/contest/1341/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int a[n+1];
        int psa[n+1];
        psa[0] = 0;
        for(int i = 1; i <= n; i++) {
            psa[i] = 0;
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++) {
            psa[i] = psa[i-1];

            if(2 <= i and i <= n-1) {
                if(a[i-1] < a[i] and a[i] > a[i+1]) {
                    psa[i]++;
                }
            }
        }

        // for(int i = 1; i <= n; i++) {
        //     cerr << psa[i] << " ";
        // }
        // cerr << endl;

        int ma = INT_MIN;
        int maiind = -1;
        for(int i = k; i <= n; i++) {
            int pieces = (psa[i-1]-psa[(i-k)+2-1])+1;
            // cerr << "on " << i << endl;
            // watch(i-1)
            // watch((i-k)+2)
            if(pieces > ma) {
                ma = pieces;
                maiind = (i-k)+1; 
            }
        }

        cout << ma << " " << maiind << endl;
    }   
}