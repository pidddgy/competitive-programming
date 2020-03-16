// https://codeforces.com/contest/1325/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        int a[n+1];
        int sum = 0;
        unordered_map<int, bool> seen;
        for(int i = 1; i <= n; i++) {
            int _;
            cin >> _;

            if(!seen[_]) {
                sum++;
                seen[_] = true;
            }
        }

        cout << sum << endl;
    }

}