// https://codeforces.com/contest/1370/problem/C
#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

bool isPrime(int a) {
    for(int i = 2; i*i <= a; i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

void solve(int n) {
    if(n == 1) {
        cout << "FastestFinger" << endl;
        return;
    }

    if((n & 1) or n == 2) {
        cout << "Ashishgup" << endl;
        return;
    }
    // if n has any odd factors, remove them all

    // have odd factors, have >= 2 counts of 2 in p factorization or have >= 2 odd factors
    bool a = false;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            if((i&1) or (n/i)&1) {
                a = true;
            }
        }
    }

    bool b = (n%4==0);

    while(n%2==0) {
        n /= 2;
    }

    bool c = !isPrime(n);

    if(a and (b or c)) {
        cout << "Ashishgup" << endl;
    } else {
        cout << "FastestFinger" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        solve(n);
    }
}
