// https://codeforces.com/contest/911/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 1700;

int a[maxn];
int n, m;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    

    int parity = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(a[i] > a[j]) {
                parity ^= 1;
            }
        }
    }

    cin >> m;
    for(int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

        int d = r-l+1;
        int p = (d*(d-1))/2;

        parity ^= p%2;
        
        if(parity) {
            cout << "odd" << endl;
        } else {
            cout << "even" << endl;
        }
    }
}
