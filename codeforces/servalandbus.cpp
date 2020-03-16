// http://codeforces.com/problemset/problem/1153/A

#include <bits/stdc++.h>
#define maxt 10100

using namespace std;
int main() {
    int n, t;
    cin >> n >> t;

    int best = 2147483647;
    int ans = 420;
    for(int i = 1; i <= n; i++) {
        int s, d;
        cin >> s >> d;

        while(s < t) s += d;
        
        if(s < best) {
            best = s;
            ans = i;
        }
    }

    cout << ans << endl;
}
