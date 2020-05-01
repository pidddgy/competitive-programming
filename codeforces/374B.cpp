// https://codeforces.com/contest/374/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a;
    cin >> a;

    int run = 0;
    int ans = 1;
    for(int i = 1; i < a.size(); i++) {
        if((a[i]-'0') + (a[i-1]-'0') == 9) {
            run++;
        } else {
            if(run%2==0){
                // watch(run)
                ans *= run/2+1;
            }
            run = 0;
        }
    }

    if(run%2==0){
        ans *= run/2+1;
    }
    cout << ans << endl;
}