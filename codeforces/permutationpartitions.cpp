// https://codeforces.com/contest/1326/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int n, k;
    cin >> n >> k;

    int ma = 0;
    unordered_map<int, bool> use;
    for(int i = n; i >= n-k+1; i--) {
        ma += i;
        // cerr << "using " << i << endl;
        use[i] = true;
    }

    int first = -1;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(use[a[i]] and first == -1) {
            // cerr << "first is " << i << endl;
            first = i;
        }
    }

    assert(first != -1);

    int last = first;
    int parts = 1;
    for(int i = first+1; i <= n; i++) {
        if(use[a[i]]) {
            parts *= i-last;
            parts %= 998244353;

            last = i;
        }
    }

    cout << ma << " " << parts << endl;
}