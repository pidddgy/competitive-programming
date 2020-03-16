// https://dmoj.ca/problem/dmopc19c3p0

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    while(N--) {
        long double a[13];
        for(int i = 1; i <= 10; i++) {
            cin >> a[i];
        }

        bool arith = true;
        bool geo = true;

        for(int i = 3; i <= 10; i++) {
            if(a[i-1] - a[i-2] != a[i] - a[i-1]) {
                arith = false;
                // cout << "failed on " << i << endl;
            }
        }

        int A = a[1];
        int R = a[2]/a[1];
        for(int i = 3; i <= 10; i++) {
            if(a[i] != A*pow(R,i-1)) {
                geo = false;
                // cout << "failed on " << i << endl;
            }
        }

        if(arith and geo) {
            cout << "both" << endl;
        } else if(arith) {
            cout << "arithmetic" << endl;
        } else if(geo) {
            cout << "geometric" << endl;
        } else {
            cout << "neither" << endl;
        }
        
        // cout << endl;
    }
}