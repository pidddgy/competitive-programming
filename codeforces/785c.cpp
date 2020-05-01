// https://codeforces.com/contest/785/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long long

int trng(int n) {
    return (n*(n+1))/2;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // int barn = n;
    // int prev = n;
    // int day = 1;
    // while(barn > 0) {
    //     barn += m;
    //     if(barn > n) barn = n;

    //     barn -= day;

    //     cout << "day " << day << " - barn is " << barn << ", prev is " << prev << ", difference is " << prev-barn << endl;
    //     prev = barn;
    //     day++;
    // }
    int l = 0;
    int r = 2e9;
    r += 500;
    watch(l)
    watch(r)
    int lastgood = 0;
    while(l <= r) {
        int mid =(l+r)/2;

        int t = trng(mid);

        if(t+m >= n) {
            lastgood = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    watch(lastgood)
    
    if(lastgood == 0) cout << n << endl;
    else cout << lastgood+m << endl;
}