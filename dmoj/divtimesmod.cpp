// https://codeforces.com/contest/1087/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, i;
    cin >> n >> k;

    for(i = k-1; i >= 0; i--) {
        if(n%i == 0) break; 
    }

    cout << (n/i) * k+i << endl;
}
