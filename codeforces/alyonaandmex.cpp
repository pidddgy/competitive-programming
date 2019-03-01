// http://codeforces.com/problemset/problem/682/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);

    int cur = 1;
    for(int i = 0; i < N; i++) {
        if(a[i] >= cur) cur++;
    }

    cout << cur << endl;

}
