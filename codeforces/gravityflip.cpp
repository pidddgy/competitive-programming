// http://codeforces.com/contest/405/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    sort(a, a+N);

    for(auto x: a) cout << x << " ";
    cout << endl;
}
