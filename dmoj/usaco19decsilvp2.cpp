// https://dmoj.ca/problem/usaco19decsilvp2

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 50500;

int N, L, T = 0;
int w[maxn], x[maxn], d[maxn], wtemp[maxn], xtemp[maxn], dtemp[maxn], inds[maxn];

bool compInd(int &l, int &r) {
    return xtemp[l] < xtemp[r];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for(int i = 1; i <= N; i++) {
        inds[i] = i;
        cin >> wtemp[i] >> xtemp[i] >> dtemp[i];
    }

    sort(inds+1, inds+N+1, compInd);

    for(int ind = 1; ind <= N; ind++) {
        int i = inds[ind];

        w[ind] = wtemp[i];
        x[ind] = xtemp[i];
        d[ind] = dtemp[i];
    }

    vector<int> l = {-1}, r = {-1};
    for(int i = 1; i <= N; i++) {
        if(d[i] == -1) l.emplace_back(x[i]);
        else r.emplace_back(x[i]);
    }

    vector<pii> v;

    for(int i = 1; i < l.size(); i++) {
        v.emplace_back(l[i], w[i]);
    }

    for(int i = 1; i < r.size(); i++) {
        int ind = l.size()-1 + i;
        v.emplace_back(L-r[i], w[ind]);
    }

    sort(v.begin(), v.end());

    int tot = 0;
    for(pii p: v) {
        tot += p.se;
    }

    for(pii p: v) {
        tot -= 2*p.se;
        if(tot <= 0) {
            T = p.fi;
            break;
        }
    }

    queue<int> Q;

    int ans = 0;

    for(int i = 1; i <= N; i++) {
        
        if(d[i] == -1) {
            while(!Q.empty() and Q.front() + 2*T < x[i]) {
                Q.pop();
            }
            ans += Q.size();
        } else {
            Q.push(x[i]);
        }
    }

    cout << ans << endl;
}
