// https://codeforces.com/contest/727/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

struct person {
    int a, b, ind;

    person(int aa, int bb, int indd) {
        a = aa;
        b = bb;
        ind = indd;
    }
};

struct Compare {
    bool operator()(person l, person r) {
        return pii(l.a, l.b) < pii(r.a, r.b);
    }
};

const int maxn = 100500;
vector<string> sizes = {"S", "M", "L", "XL", "XXL", "XXXL"};
map<string, int> id;
int cnt[10];
string ans[maxn];

vector<person> want;

void no() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < sz(sizes); i++) {
        id[sizes[i]] = i+1;
    }

    for(int i = 1; i <= 6; i++) {
        cin >> cnt[i];
    }

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        if(s.find(',') == string::npos) {
            ans[i] = s;
            if(cnt[id[s]] <= 0) no();
            cnt[id[s]]--;
        } else {
            string l;
            string r;
            
            int ind;
            for(int j = 0; j < sz(s); j++) {
                if(s[j] == ',') ind = j;
            }

            for(int j = 0; j < ind; j++) {
                l += s[j];
            }

            for(int j = ind+1; j < sz(s); j++) {
                r += s[j];
            }

            want.emplace_back(min(id[l], id[r]), max(id[l], id[r]), i);
        }
    }

    sort(all(want), Compare());

    for(person x: want) {
        // cerr << x.fi << " " << x.se << endl;
        if(cnt[x.a]) {
            cnt[x.a]--;
            ans[x.ind] = sizes[x.a-1];
        } else if(cnt[x.b]) {
            cnt[x.b]--;
            ans[x.ind] = sizes[x.b-1];
        } else no();
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}

/*

each person that only wants one type of shirt needs to get that shirt

go from small, med, large, etcetc, giving the current to as many as possible.

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
