// https://codeforces.com/contest/1332/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int gcd(int a, int b)
{
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // cerr << gcd(4, 9) << endl;
    // #define cerr if(false) cerr
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int a[N+1];
        for(int i = 1; i <= N; i++) cin >> a[i];

        int color[N+1];
        for(int i = 1; i <= N; i++) color[i] = -1;

        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        assert(primes.size() == 11);

        int curColor = 1;
        int used = 0;
        set<int> S;
        for(int i = 0; i < primes.size(); i++) {
            bool curuse = false;
            for(int j = 1; j <= N; j++) {
                if(color[j] == -1 and ((a[j]%primes[i]) == 0) ) {
                    color[j] = curColor;
                    curuse = true;
                }
            }

            if(curuse) {
                S.emplace(primes[i]);
                curColor++;
            }
        }
        
        cout << S.size() << endl;
        for(int i = 1; i <= N; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
    }

}