// https://dmoj.ca/problem/wac2p2

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fi first
#define se second
#define endl '\n'

using namespace std;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    map<int, int> price; // min price per day

    vector<int> chd;
    map<int, bool> have;
    price[N] = 1000000;
    have[N] = true;
    chd.emplace_back(N);

    int last = N;
    int old = 1000000;
    map<int, int> incr;
    incr[N] = 1000000;

    while(Q--) {
        int d, p;
        cin >> d >> p;

        if(!have[d]) {
            chd.emplace_back(d);
            have[d] = true;
        }

        if(price[d] == 0) price[d] = p;
        else price[d] = min(price[d], p);

        if(incr[d]==0) incr[d] = min(old, price[d]); 
        incr[d] = min(min(incr[d], price[d]), old);
        

        last = d;
        old = p;
    }

    map<int, int> prcnt; // how many costumes can u buy with price i
    for(int i = 0; i < chd.size()-1; i++) {
        int x = price[chd[i]];
        prcnt[x] += chd[i]-chd[i+1]-1;
        prcnt[incr[chd[i]]]++;
    }

    prcnt[price[chd[chd.size()-1]]] += chd[chd.size()-1]-1; // careful
    prcnt[incr[chd[chd.size()-1]]]++;
    int ans = 0;
    int rem = M;

    // for(pii x: prcnt) {
    //     cout << x.fi << " " << x.se << endl;
    // }
    for(pii x: prcnt) {
        if(x.se > rem) {
            ans += rem*x.fi;
            break;
        } else {
            ans += x.se*x.fi;
            rem -= x.se;
        }
    }

    cout << ans << endl;
}

/*
5 2 6
5 6
4 2
3 1
2 4
2 5
2 6

-> 2


*/