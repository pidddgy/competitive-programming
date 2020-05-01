// https://codeforces.com/contest/1015/problem/D

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int n, k, s;
    cin >> n >> k >> s;

    if((n-1) * k < s or k > s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int i = 1;
        while(k--) {
            int dist = min(n-1, s-k);
            if(i+dist <= n) {
                i += dist;
            } else if(i-dist >= 1) {
                i -= dist;
            } else {
                assert(false);
            }

            cout << i << " ";
            s -= dist;
            
        }
        cout << endl;
    }
}