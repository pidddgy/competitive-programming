// pray

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ld long double
using namespace std;
int main() {
    int N;
    cin >> N;

    pii a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a, a+N);

    ld ans = 0;
    for(int i = 1; i < N; i++) {
        ld dis = a[i].se - a[i-1].se;
        ld time = a[i].fi - a[i-1].fi;
        ans = max(ans, abs(dis/time));
    }

    cout << ans << endl;



}

/*
3
0 100
20 50
10 120
*/