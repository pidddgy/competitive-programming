// https://codeforces.com/contest/1225/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

vector<int> p2(int n) { 
    vector<int> res;
    for(int i = 31; i >= 0; i--) {
        if(pow(2, i) <= n) {
            res.emplace_back(pow(2, i));
            n -= pow(2, i);
        }
    }
    
    return res;
} 
  
bool f(int a, int summands) {
    if(summands > a or summands < p2(a).size()) {
        return false;
    } else {
        return true;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    // represent n as i 
    for(int i = 1; i <= 500; i++) {
        
        int target = n - (p*i);
        watch(i)
        watch(target)
        watch(f(target, i))
        if(f(target, i)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}