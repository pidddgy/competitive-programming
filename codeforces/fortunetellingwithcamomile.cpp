// https://codeforces.com/problemsets/acmsguru/problem/99999/404

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    string a[M+1];
    for(int i = 1; i <= M; i++) cin >> a[i];

    int cur = 0;
    while(N--) {
        cur++;
        if(cur == M+1) cur = 1;
    }

    cout << a[cur] << endl;
}