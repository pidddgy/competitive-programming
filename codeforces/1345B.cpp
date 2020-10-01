//http://m3.codeforces.com/contest/1345/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define EPS 0.0001
#define int long long
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

int trng(int n) {
    return(n*(n+1))/2;
}
int f(int n) {
    return (trng(n)*3)-n;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // cout << f(7) << endl;

    int t;
    cin >> t;

    while(t--) {
        int ans = 0;
        int n;
        cin >> n;

        while(n) {
            int l = 1;
            int r = n;
            int lastgood = -1;
            while(l <= r) {
                int m = (l+r)/2;

                cerr << "currently on " << m << endl;
                watch(f(m))
                if(f(m) <= n) {
                    cerr << "good" << endl;
                    lastgood = m;
                    l = m+1;
                } else {
                    cerr << "lowering" << endl;
                    r = m-1;
                }
            }

            if(lastgood == -1) break;

            ans++;
            cerr << "using " << lastgood << endl;
            cerr << "sutbracting " << f(lastgood) << endl;
            n -= f(lastgood);
        }

        cout << ans << endl;
    }
    
}