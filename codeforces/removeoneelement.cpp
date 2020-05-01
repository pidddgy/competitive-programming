// https://codeforces.com/contest/1272/problem/D

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    pii run[N+1];
    for(int i = 1; i <= N; i++) {
        run[i] = make_pair(-1, -1);
    }

    int last = 1;
    run[1].fi = 1;

    for(int i = 2; i <= N; i++) {
        if(a[i] <= a[i-1]) {
            run[run[i-1].fi].se = i-1;
            run[i-1].se = i-1;
            run[i].fi = i;
        } else {
            run[i].fi = run[i-1].fi;
        }

    }
    run[N].se = N;
    run[run[N].fi].se = N;

    for(int i = 2; i <= N; i++) {
        if(run[i].se == -1) {
            run[i].se = run[i-1].se;
        }
    }
    for(int i = 1; i <= N; i++) {
        cerr << run[i].fi << " ";
    }
    cerr << endl;

    for(int i = 1; i <= N; i++) {
        cerr << run[i].se << " ";
    }
    cerr << endl;

    int ans = 0;
    for(int i = 2; i <= N-1; i++) {
        if(a[i-1] < a[i+1] and run[i-1] != run[i+1]) {
            int llen = (run[i-1].se - run[i-1].fi) + 1;
            int rlen = (run[i+1].se - run[i+1].fi) + 1;
            if(run[i-1].se == i) llen--;
            if(run[i+1].fi == i) rlen--;
            watch(run[i-1].se - run[i-1].fi)
            watch(run[i+1].se - run[i+1].fi)
            cerr << "removing " << i << " results in " << llen+rlen << endl;
            ans = max(ans, llen+rlen);
            cerr << endl;
        }
    }

    for(int i = 1; i <= N; i++) {
        ans = max(ans, run[i].se - run[i].fi + 1);
    }

    cout << ans << endl;


}