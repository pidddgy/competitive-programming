// https://codeforces.com/contest/1303/problem/B

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int T;
    cin >> T;
    
    while(T--) {
        int n, g, b;
        cin >> n >> g >> b;

        // good ashpalt needed, bad needed
        int gn = n/2;
        if(n % 2== 1) gn++;

        int bn = n-gn;

        int l = 1;
        int r = 1000000000000000000;
        
        int needed = LLONG_MAX;
        while(l <= r) {
            
            int m = (l+r) / 2;
            watch(m)

            int G = 0;
            int B = 0;

            int s = m/(g+b);
            watch(s)

            G += s*g;
            B += s*b;

            int rem = m-(s*(g+b));

            watch(rem)

            G += min(g, rem);

            rem -= min(g, rem);

            watch(rem)
            B += min(b, rem);
            watch(B)
            
            watch(G)
            watch(B)
            if(G + B >= n and G >= gn) {
                r = m-1;
                cerr << "good" << endl;

                needed = min(needed, m);
            } else {
                cerr << "bad" << endl;
                l = m+1;
            }

            cerr << endl;
        }

        cout << needed << endl;
    }
}