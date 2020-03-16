// https://codeforces.com/contest/1141/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;

unordered_map<ll, ll> dp;

ll f(ll a, ll b, ll cur) {
    if(dp.find(a) != dp.end()) {
        return dp[a];
    }
    if(a > b) return -1;
    else if(a == b) {
        cout << cur << endl;
        exit(0);
    }


    if(f(a*2, b, cur+1) != -1 || f(a*3, b, cur+1) != -1)  {
if(f(a*2, b, cur+1) == -1 && f(a*3, b, cur+1) == -1)
            dp[a] = -1;
        else if(f(a*2, b, cur+1) == -1)
            dp[a] = f(a*3, b, cur+1);
        else if(f(a*3, b, cur+1) == -1)
            dp[a] = f(a*2, b, cur+1);
        else
            dp[a] = min(f(a*3, b, cur+1), f(a*2, b, cur+1));
        return dp[a];
    }
        

    return -1;

}


int main() {
    ll a;
    ll b;
    cin >> a >> b;

    cout << f(a, b, 0) << endl;     
}
