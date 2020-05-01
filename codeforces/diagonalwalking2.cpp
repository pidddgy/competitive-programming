// https://codeforces.com/contest/1036/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long

    int Q;
    cin >> Q;

    while(Q--) {
        int n, m, k;
        cin >> n >> m >> k;

        if((n%2) != (m%2)) {
            k--;
            if((n%2) != (k%2)) {
                n--;
            } else if((m%2) != (k%2)) {
                m--;
            }
            // cerr << "HI" << endl;
        }

        if((n%2) != (k%2)) {
            k -= 2;
            n--;
            m--;
            // cerr << "HIII" << endl;
        }

        if(k >= max(n, m)) {
            cout << k << endl;
        } else {
            cout << -1 << endl;
        }
    }
}