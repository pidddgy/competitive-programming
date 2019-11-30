// https://dmoj.ca/problem/ds1

#include <bits/stdc++.h>
#define MAXN 100005 
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
#define endl '\n'
using namespace std;
ll a[MAXN];
ll cnt[MAXN];

ll segtree[MAXN * 4];
ll cntSegtree[MAXN * 4];

ll left(ll n) {
    return n*2+1;
}

ll right(ll n) {
    return n*2+2;
}

ll mid(ll a, ll b) {
    return (a+b)/2;
} 

void build(ll ind, ll l, ll r) {
    if(l == r) {
        segtree[ind] = a[l];
    } else {
        ll m = mid(l, r);
        build(left(ind), l, m);
        build(right(ind), m+1, r);

        segtree[ind] = segtree[left(ind)] + segtree[right(ind)];
    }
}

void buildCnt(ll ind, ll l, ll r) {
    if(l == r) {
        cntSegtree[ind] = cnt[l];
    } else {
        ll m = mid(l, r);
        buildCnt(left(ind), l, m);
        buildCnt(right(ind), m+1, r);

        cntSegtree[ind] = cntSegtree[left(ind)] + cntSegtree[right(ind)];
    }

}

ll uind;
void update(ll ind, ll l, ll r) {
    if(l == r) {
        segtree[ind] = a[uind];
        return;
    }

    ll m = mid(l, r);
    if(uind <= m) {
        update(left(ind), l, m);
    } else {
        update(right(ind), m+1, r);
    }

    segtree[ind] = segtree[left(ind)] + segtree[right(ind)];
}

ll updatesv;
void updateQ(ll ind, ll l, ll r) {
    if(l == r) {
        cntSegtree[ind] = cnt[l];
        return;
    }

    ll m = mid(l, r);
    if(updatesv <= m) {
        updateQ(left(ind), l, m);
    } else {
        updateQ(right(ind), m+1, r);
    }

    cntSegtree[ind] = cntSegtree[left(ind)] + cntSegtree[right(ind)];
}

ll ql, qr;
ll queryQ(ll ind, ll l, ll r) {
    if(ql <= l && r <= qr) {
        return cntSegtree[ind];
    }

    ll ret = 0;
    ll m = mid(l, r);

    if(ql <= m) ret += queryQ(left(ind), l, m);
    if(qr >= m+1) ret += queryQ(right(ind), m+1, r);
    
    return ret;
}

ll queryS(ll ind, ll l, ll r) {


    if(ql <= l && r <= qr) {
        return segtree[ind];
    }

    ll ret = 0;
    ll m = mid(l, r);

    if(ql <= m) ret += queryS(left(ind), l, m);
    if(qr >= m+1) ret += queryS(right(ind), m+1, r);
    
    return ret;
}


int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;

    for(ll i = 1; i <= N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    build(1, 1, MAXN);
    buildCnt(1, 1, MAXN);

    for(ll i = 1; i <= M; i++) {
        char t;
        cin >> t;

        if(t == 'S') {
            cin >> ql >> qr;

            cout << queryS(1, 1, MAXN) << endl;
        } else if(t == 'C') {
            ll x, v;
            cin >> x >> v;

            ll a_x = a[x];
            updatesv = a_x;
            cnt[a[x]]--;

            a[x] = v;
            uind = x;
            
            update(1, 1, MAXN);

            updateQ(1, 1, MAXN);

            cnt[v]++;
            updatesv = v;
            updateQ(1, 1, MAXN);

        } else if(t == 'Q') {
            ql = 1;
            cin >> qr;

            cout << queryQ(1, 1, MAXN) << endl;
        }
    }

}