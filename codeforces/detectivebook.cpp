// https://codeforces.com/contest/1140/problem/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N];
    for(auto &x: a) {
        int b; cin >> b;
        x=--b;
    }

    int pos = 0;
    int cnt = 0;

    while(pos < N) {
        cnt++;
        int maax = pos;

        while(pos <= maax && pos < N) {
            maax = max(maax, a[pos]);
            pos++;
        }
    }


    cout << cnt << endl;

}
