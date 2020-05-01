// https://codeforces.com/contest/1186/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ld long double
#define int long long
const ld EPS = 1e-12;
const int maxn = 100050;

int a[maxn];
bool canAdd[maxn];

bool closeEnough(ld x, ld y) {
    return(abs(x-y) <= EPS);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        ld x;
        cin >> x;
        if(not closeEnough(abs(x-floor(x)), 0.0)) {
            canAdd[i] = true;
        }

        // watch(floor(x));

        sum += floor(x);

        a[i] = floor(x);
        // watch(a[i])
    }

    for(int i = 1; i <= n; i++) {
        if(sum < 0 and canAdd[i]) {
            a[i]++;
            sum++;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
}