// https://dmoj.ca/problem/dmopc15c1p4

#include <bits/stdc++.h>
#define maxn 148834 
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
int main() {
    #define int long long
    int n, x;
    cin >> n >> x;

    bool pr[maxn];
    for(int i = 0; i < maxn; i++) {
        pr[i] = true;
    }

    for(int i = 2; i <= n; i++) {
        if(pr[i])
        for(int j = i+i; j <= n; j+=i) {
            pr[j] = false;
        }
    }   
    
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(pr[i]) {
            // cout << i << " is prime " << endl;
            // cout << "remainder is " << n-i << endl;

            // cout << "if last takes zero, we have " << ((n-i) / x)+1 << " possibilities " << endl;
            // cout << "if last takes one, we have " << ((n-i-1) / x)+1 << " possibilities " << endl;
            ans += ((n-i) / x)+1;

            
            if(n-i != 0) ans += ((n-i-1) / x)+1;

            // cout << endl;
        }
    }

    cout << ans << endl;
    
    assert(ans >= 0);
}