// http://codeforces.com/contest/1203/problem/E

#include <bits/stdc++.h>
using namespace std;

bool used[150031];

int main() {
    int N;
    cin >> N; 
    
    int a[N];
    for(auto &x: a) {
        cin >> x;
    }

    sort(a, a+N);

    // try below, then cur, the nup
    int ans = 0;
    for(auto x: a) {
        if (!used[x-1] and x-1 >= 1) {
            used[x-1] = true;
            ans++;
        } else if(!used[x]) {
            used[x] = true;
            ans++;
        } else if(!used[x+1] and x+1 <= 150001) {
            used[x+1] = true;
            ans++;
        }
    }

    cout << ans << endl;


}