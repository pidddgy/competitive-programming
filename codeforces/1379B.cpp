// https://codeforces.com/contest/1379/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

// https://www.geeksforgeeks.org/multiple-of-x-closest-to-n/
// Function to calculate the smallest multiple 
int cm(int n, int x) 
{    
    if(x>n) 
       return x; 
  
    n = n + x/2; 
    n = n - (n%x); 
    return n; 
} 


void solve() {
    int l, r, m;
    cin >> l >> r >> m;
    
    // max we can add/reduce
    int ma = r-l;
    for(int a = l; a <= r; a++) {
        int val = cm(m, a);
        if(val == 0) continue;

        int need = m-val;

        if(abs(need) > ma) {
            continue;
        }

        if(need >= 0) {
            cout << a << " " << l+need << " " << l << endl;
        } else {
            cout << a << " " << r+need << " " << r << endl;
        }

        break;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}