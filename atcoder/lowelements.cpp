// https://atcoder.jp/contests/abc152/tasks/abc152_c

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N];
    set<int> S;
    int ans = 0 ;

    int ma = 0;
    for(int i = 1; i <= N; i++) {
        if(a[i])
        ma = max(a[i], a[i-1]);
    }
}