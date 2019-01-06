// https://dmoj.ca/problem/acc1p3

#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N, T;
    cin >> N >> T;
    pii P[N];
    for(int i = 0; i < N; i++)  {
        ll a, b;
        cin >> a >> b;
        P[i].fi = a;
        P[i].se = b;
    }

    // Binary search 
    ll l = 0;
    ll r = 1000000000000000005;

    for(;;) {
        ll v = (l+r)/2;
        cout << "v is " << v << endl;

        // Calculate how much poutine we can eat if we only eat poutines that give us v happiness
        ll H = 0;
        ll eaten = 0;

        for(int i = 0; i < N; i++) {
            ll times = ceil((P[i].fi - v) / P[i].se) + 1;
            ll lastTerm = P[i].fi - (times-1) * P[i].se;

            H = (H+times*((P[i].fi + lastTerm) / 2)) % 998244353;
            eaten += times;
        }
        cout << "eaten is " << eaten << endl;
        cout << "happiness is " << H << endl;
        if(eaten == T) {
            cout << H % 998244353 << "\n";
            break;
        } 
        else if (eaten > T)
            l = v;
        else if (eaten < T)
            r = v;
    }
}
