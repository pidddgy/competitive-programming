// https://codeforces.com/contest/1062/problem/B    

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 1000500;
int spf[maxn];

void sieve() {
    spf[1] = 1;
    for(int i = 2; i < maxn; i++) {
        spf[i] = i;
    }

    for(int i = 4; i < maxn; i += 2) spf[i] = 2;

    for(int i = 3; i*i < maxn; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j < maxn; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factorize(int x) {
    vector<int> res;

    while(x != 1) {
        res.emplace_back(spf[x]);
        x /= spf[x];
    }

    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    sieve();
    for(int x: factorize(N)) {
        cerr << x << " ";
    }
    cerr << endl;

    int ans = 0;

    vector<int> f = factorize(N);
    set<int> S;
    unordered_map<int, int> cnt;
    for(int x: f) {
        cnt[x]++;
        S.emplace(x);
    }

    int len = 0;
    for(pii x: cnt) {
        len = max(len, x.se);
    }

    watch(len)
    int p = 1;

    while(p < len) {
        p <<= 1;
    }

    ans = log2(p);
    watch(ans)
    for(int x: f) {
        if(cnt[x] != p) {
            cerr << "adding extra" << endl;
            ans++;
            break;
        }
    }

    int prod = 1;
    for(int x: S) {
        prod *= x;
    }

    if(prod == N) ans = 0;
    cout << prod << " " << ans << endl;


}