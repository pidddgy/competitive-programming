// https://codeforces.com/contest/1165/problem/D    

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    #define watch(x) cerr << (#x) << " is " << (x) << endl;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int val = (*min_element(a+1, a+n+1)) * (*max_element(a+1, a+n+1));
        set<int> divis;
        for(int i = 2; i <= min((int)sqrt(val)+5, val-1); i++) {
            if(val % i == 0) {
                divis.emplace(i);
                divis.emplace(val/i);
            }
        }

        bool bad = false;
        for(int i = 1; i <= n; i++) {
            if(val % a[i] != 0) {
                bad = true; 
                break;
            }
        }

        if(divis.size() != n) {
            watch(divis.size())
            bad = true;
        }

        if(bad) {
            cout << -1 << endl;
        } else {
            cout << val << endl;
        }
    }
}