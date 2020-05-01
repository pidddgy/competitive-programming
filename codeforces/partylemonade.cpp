// https://codeforces.com/contest/913/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define scope for(int scope = 0; scope < 1; scope++)
// #define cerr if(false) cerr
int main() {
    #define int unsigned long long
    #define watch(x) cerr << (#x) << " is " << (x) << endl;
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, L;
    cin >> n >> L;

    int a[36];
    for(int i = 0; i <= 36; i++) a[i] = -1;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < 32; i++) {
        if(a[i+1] == -1 or a[i]*2 < a[i+1]) {
            a[i+1] = a[i]*2;
        }
    }

    int cost = 0;
    for(int i = 0; i < 32; i++) {
        cost = min(cost, a[i]);

        if(L & (1 << i)) {
            cost += a[i];
        }
    }

    cout << cost << endl;
    

}