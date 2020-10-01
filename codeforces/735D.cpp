// https://codeforces.com/contest/735/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

bool isPrime(int a) {
    for(int i = 2; i*i <= a; i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(isPrime(n)) {
        cout << 1 << endl;
    } else if(n % 2 == 0) {
        cout << 2 << endl;
    } else {
        if(isPrime(n-2)) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
}
