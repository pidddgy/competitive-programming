// http://codeforces.com/contest/1213/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long
    int N;
    cin >> N;

    int a[N];
    for(auto &x: a) cin >> x;

    int ev = 0;
    int od = 0;
    for(int i = 0; i < N; i++) {
        if(a[i]%2==0) {
            ev++;
        }
        else od++;
    }
    cout << min(ev, od) << endl;
}