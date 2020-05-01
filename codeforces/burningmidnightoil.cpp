// https://codeforces.com/contest/165/problem/B

#include <bits/stdc++.h>
#define cerr if(false) cerr
using namespace std;
int main() {
    #define int long long
    int n, k;
    cin >> n >> k;

    int l = 1;
    int r = n+1;
    int lastgood = -1;
    while(l <= r) {
        int m = (l+r)/2;
        cerr << "trying " << m << endl;
        int lines = 0;
        for(int p = 0;; p++) {
            if(floor(m / pow(k, p)) == 0) break; 

            cerr << "on " << p << endl;
            lines += floor(m/pow(k, p));
            cerr << "adding " << floor(m/pow(k, p)) << endl;
        }


        if(lines >= n) {
            r = m-1;
            lastgood = m;
        } else {
            l = m+1;
        }
        cerr << endl;
    }

    cout << lastgood << endl;
}