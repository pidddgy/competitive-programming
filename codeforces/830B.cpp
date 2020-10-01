// https://codeforces.com/problemset/problem/830/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define cerr if(false) cerr

const int maxn = 100500;

// bit stores number of marked
int n, a[maxn], bit[maxn];
map<int, set<int>> pos;

void upd(int ind, int val) {
    for(int i = ind; i <= 1e5; i += i &-i) {
        bit[i] += val;
    }
}

int sum(int ind) {
    int res = 0;
    for(int i = ind; i >= 1; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

int query(int l, int r) {
    if(l <= r) {
        return sum(r)-sum(l-1);
    } else {
        int right = sum(n)-sum(l-1);
        int left = sum(r);

        return right+left;
    }
}

int amt(int l, int r) {
    if(l <= r) {
        return (r-l)+1;
    } else {
        return (n-l+1) + r;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    set<int> vals;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[i] = x;
        pos[x].emplace(i);
        vals.emplace(x);
    }

    int cur = 1;
    int ans = 0;
    for(int v: vals) {
        watch(v)
        while(pos[v].size()) {
            int next;

            if(pos[v].lower_bound(cur) == pos[v].end()) {
                next = *pos[v].begin();
            } else {
                next = *pos[v].lower_bound(cur);
            }

            cerr << "going from " << cur << " to " << next << endl;
            cerr << "costs " << amt(cur, next) - query(cur, next) << endl;
            watch(amt(cur, next))
            ans += amt(cur, next) - query(cur, next);
            
            upd(next, 1);
            pos[v].erase(next);
            cur = next;
            cerr << endl;
        }
    }

    cout << ans << endl;
}