// https://codeforces.com/contest/1143/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    int last1 = -1;
    int last0 = -1;

    for(int i = 0; i < N; i++) {
        if(a[i] == 1) last1 = i;
        if(a[i] == 0) last0 = i; 
    }

    cout << min(last1, last0) + 1 << endl;
}
