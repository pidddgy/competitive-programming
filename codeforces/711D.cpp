// https://codeforces.com/contest/711/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define int long long

const int maxn = 200500;
const int MOD = 1000000007;

int n;
int a[maxn], vis[maxn], disj[maxn], sz[maxn];

int modpow(int a, int exp){
    if(exp == 0) return 1;
    int t = modpow(a,exp/2);
    if(exp%2) return t*t%MOD*a%MOD;
    return t*t%MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int findp(int n) {
    if(disj[n] == n) return n;
    else return disj[n] = findp(disj[n]);
}

void merge(int a, int b) {
    int c = findp(a), d = findp(b);
    if(c == d) return;

    disj[c] = d;
    sz[d] += sz[c];
}

vector<int> path;
vector<vector<int>> cycles;

void dfs(int v) {
    vis[v] = 1;
    path.push_back(v);

    int to = a[v];
    if(vis[to] != 2) {
        if(vis[to] == 1) {
            cycles.emplace_back(vector<int>());
            int i = path.size()-1;

            while(path[i] != to) {
                cycles.back().emplace_back(path[i]);
                i--;
            }
            cycles.back().emplace_back(to);
        } else {
            dfs(to);
        }
    }
    path.pop_back();
    vis[v] = 2;
}

int modmul(int a, int b) {
    return ((a%MOD)*(b%MOD))%MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        disj[i] = i;
        sz[i] = 1;
    }

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        merge(i, a[i]);
    }


    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(vis[findp(i)] == 0) {
            dfs(i);
            vis[findp(i)] = true;
            ans = modmul(ans, modpow(2, sz[findp(i)]));
            ans = modmul(ans, modpow(2, cycles.back().size())-2);
            ans = modmul(ans, modinv(modpow(2, cycles.back().size())));
            ans %= MOD;
        }
    }

    cout << (ans+MOD)%MOD << endl;
}
