// https://codeforces.com/contest/1141/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long 
    int N;
    cin >> N;
    int a[N];
    a[0] = 0;
    for(int i = 1; i < N; i++) {
        cin >> a[i];
    }

    unordered_set<int> S;
    int mi = 2147483647;
    int ma = -2147483647;

    for(int i = 1; i < N; i++) a[i] += a[i-1];

    // check if they'll ever land in the same number
    for(auto x: a) {
        mi = min(mi, x);
        ma = max(ma, x);

        if(S.find(x) != S.end() || x > N) {
            cout << -1 << endl;
            return 0;
        } else S.emplace(x);
    }

    if(abs(1 - mi) == abs(N - ma) ) {
        for(auto x: a) {
            cout << x+abs(1 - mi) << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

}
