// https://codeforces.com/contest/924/problem/B

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int n, U;
    cin >> n >> U;

    int E[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> E[i];
    }

    long double ma = DBL_MIN;
    for(int i = 1; i <= n-2; i++) {
        int lb = E[i];
        int ub = E[i]+U;

        int j = i+1;
        int k = -1;

        int l = i+2;
        int r = n;

        while(l <= r) {
            int m = (l+r)/2;

            if(E[m] <= ub) {
                l = m+1;
                k = m;
            } else {
                r = m-1;
            }
        }

        if(k == -1) continue;

        watch(i)
        watch(j)
        watch(k)
        cerr << i << " can get a max of " << (E[k]-E[j])/(E[k]-E[i]) << endl; 
        ma = max(ma, (long double)(E[k]-E[j])/(E[k]-E[i]));
    }
    
    if(ma == DBL_MIN) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << ma << endl;
    }
}