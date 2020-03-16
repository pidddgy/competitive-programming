// http://codeforces.com/contest/1155/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ull unsigned long long
using namespace std;

ull GCD(ull a, ull b)
{
    if(b == 0) {
        return a;
    }
    else {
        return GCD(b, a % b);
    }
}


int main() {
    ull N, M;
    cin >> N >> M;

    ull x[N+1];
    for(ull i = 1; i <= N; i++) {
        cin >> x[i];
    }

    ull p[M+1];
    for(ull i = 1; i <= M; i++) {
        cin >> p[i];
    }

    ull diff[N+1-1];
    for(ull i = 1; i <= N-1; i++) {
        diff[i] = x[i+1]-x[i];
    }

    ull gcd = diff[1];
    for(ull i = 2; i <= N-1; i++) {
        gcd = GCD(gcd, diff[i]);
    }

    for(ull i = 1; i <= M; i++) {
        if(gcd % p[i] == 0) {
            cout << "YES" << endl;
            cout << x[1] << " " << i << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    //watch(gcd)
    //for(int i = 1; i <= N-1; i++) cout << diff[i] << endl;
}

