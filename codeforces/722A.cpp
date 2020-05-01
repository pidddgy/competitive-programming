// https://codeforces.com/problemset/problem/772/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    int a[n+1], b[n+1];
    int as = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];

        as += a[i];
    }

    if(as <= p) {
        cout << -1 << endl;
        return 0;
    }

    ld l = 0;
    ld r = 1000000000000000000;
    ld lastgood = 0;
    
    int it = 0;
    while(l <= r and it < 250) {
        ld mid = (l+r)/2;

        ld need[n+1];
        for(int i = 1; i <= n; i++) {
            need[i] = max((ld)0, mid*a[i] - b[i]);
        }

        ld sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += need[i]/mid;
        }

        if(sum > p) {
            r = mid;
        } else {
            l = mid;
            lastgood = mid;
        }

        it++;   
    }

    if(lastgood == 1000000000000000000) {
        cout << -1 << endl;
        return 0;
    }

    cout << fixed << setprecision(15) << lastgood << endl;
}