// http://codeforces.com/contest/1174/problem/A 

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N*2+1];
    for(int i = 1; i <= N*2; i++) {
        cin >> a[i];
    }

    sort(a+1, a+(N*2)+1);

    int l = 0; 
    for(int i = 1; i <= N; i++) {
        l += a[i];
    }

    int r = 0;
    for(int i = N+1; i <= N*2; i++) {
        r += a[i];
    }

    if(l == r) {
        cout << -1 << endl;
    } else {
        for(int i = 1; i <= N*2; i++) cout << a[i] << " ";
        cout << endl;
    }
}
