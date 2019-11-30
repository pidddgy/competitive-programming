// https://dmoj.ca/problem/wac2p2

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

signed main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    map<int, int> incr;
    map<int, int> price;
    map<int, bool> have;

    price[N] = 1000000;
    incr[N] = 1000000;
    have[N] = true;

    vector<int> ch;
    ch.emplace_back(N);
    int prev = 1000000;
    for(int i = 0; i < Q; i++) {
        int d, p;
        cin >> d >> p;

        if(!have[d]) {
            have[d] = true;
            ch.emplace_back(d);
        }

        if(price[d] == 0) price[d] = p;
        else price[d] = min(price[d], p);

        if(incr[d] == 0) incr[d] = min(prev, price[d]);
        else {
            incr[d] = min(prev, min(price[d], p));
        }

        prev = p;
    }

    for(int i = N; i >= 1; i--) cout << price[i] << " ";
    cout << endl;
    map<int, int> prcnt;
    for(int i = 0; i < ch.size()-1; i++) {
        int x = price[ch[i]];
        prcnt[x] += ch[i]-ch[i+1]-1;
        prcnt[incr[x]]++; 
    }

    prcnt[price[ch[ch.size()-1]]] += ch[ch.size()-1];
    prcnt[incr[ch[ch.size()-1]]]++;

    int ans = 0;
    int rem = M;

    for(pii x: prcnt) {
        cout << x.fi << " " << x.se << endl;
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