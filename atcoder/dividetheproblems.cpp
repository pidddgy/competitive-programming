// https://atcoder.jp/contests/abc132/tasks/abc132_c

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    sort(a+1, a+N+1);


    cout << a[(N/2)+1]-a[N/2] << endl;
}