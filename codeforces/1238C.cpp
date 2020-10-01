// https://codeforces.com/contest/1238/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define int long long
    #define endl '\n'

    int t;
    cin >> t;

    while(t--) {
        int h, n;
        cin >> h >> n;

        int p[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        int lf = 1;
        int ans = 0;
        for(int i = 2; i <= n; i++) {
            if(p[i-1] > p[i]+1) {
                if(lf > 1) {
                    ans += (i-lf)%2==1;
                } else {
                    ans += (i-lf)%2==0;
                }
                lf = i;
            }
        }

        if(p[n] > 1) {
            if(lf != 1) {
                ans += ((n+1)-lf)%2==1;
            } else {
                ans += ((n+1)-lf)%2==0;
            }
        }

        cout << ans << endl;
    }
}