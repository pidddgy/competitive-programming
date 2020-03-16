// http://codeforces.com/contest/1199/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int n, x, y;
    cin >> n >> x >> y;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        // cout << "currently on " << i << endl;
        bool valid = true;
        for(int j = i-x; j <= i+y; j++) {
            if(j < 1 or j > n) continue;
            else if(a[j] < a[i]) {
                valid = false;
            }
        }

        if(valid) {
            cout << i << endl;
            break;
        }
    } 
}