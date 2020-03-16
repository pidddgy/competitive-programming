// https://codeforces.com/contest/1290/problem/A

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;

        k = min(k, m-1);

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // nc = no control
        int nc = max(0, m-k-1);
        
        // i == controlled taking from left
        // j == non controlled taking from left
        
        watch(k)
        watch(nc)
        
        int best = 0;
        for(int i = 0; i <= k; i++) {

            int worst = INT_MAX;
            for(int j = 0; j <= nc; j++) {

                cerr << "if i is " << i << " and j is " << j << " we can take either at index " << i+j+1 << " or " << n - (k-i) - (nc-j) << endl;
                int l = a[i+j+1];
                int r = a[n - (k-i) - (nc-j)];

                worst = min(worst, max(l, r));
    
            }

            best = max(best, worst);
        }

        cout << best << endl;
        cerr << endl;
    }
}