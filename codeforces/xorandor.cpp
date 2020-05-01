// https://codeforces.com/contest/282/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    if(a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }

    bool agood = false;
    bool bgood = false;
    
    for(int i = 0; i < a.size(); i++) {
        agood |= (a[i]=='1');
        bgood |= (b[i]=='1');
    }

    if(a.size() == 1) {
        agood = false;
        bgood = false;
    }

    if(a == b) {
        agood = true;
        bgood= true;
    }

    if(agood and bgood) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}