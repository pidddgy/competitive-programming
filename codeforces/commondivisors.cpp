// http://codeforces.com/contest/1203/problem/C
    
#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
    


int main() {
    ll N; cin >> N;
    ll a[N+1];
    
    for(ll i = 1; i <= N; i++) {
        cin >> a[i];
    }
    
    ll g = a[1];
    
    for(ll i = 2; i <= N; i++) {
        g = gcd(g, a[i]);
    }
    
    // watch(g)

    ll ans = 0;
    for(ll i = 1; i <= sqrt(g); i++) {
        if(g%i == 0) {
            ans += 2;
        }
    
        if(i == g/i and g%i == 0) { 
            ans--;
        }
    }
    
    
    cout << ans << endl;
}