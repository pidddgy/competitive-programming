// https://codeforces.com/contest/812/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int n, S;
    cin >> n >> S;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int lastgood = 0;
    int cost = 0;

    int l = 1;
    int r = n;

    while(l <= r) {
        int m = (l+r)/2;

        int c = 0;
        int b[n+1];
        // cerr << "trying " << m << endl;
        for(int i = 1; i <= n; i++) {
            b[i] = a[i] + (i*m);
        }
        sort(b+1, b+n+1);
        for(int i = 1; i <= m; i++) {
            c += b[i];
        }

        if(c <= S) {
            // assert(m >= lastgood);
            lastgood = m;
            cost = c;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    cout << lastgood << " " << cost << endl;

}