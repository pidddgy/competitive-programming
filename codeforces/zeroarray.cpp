// http://codeforces.com/contest/1201/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int n;
    cin >> n;
    
    int a[n+1];
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] * 2 > sum) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if(sum % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}