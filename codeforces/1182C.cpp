// https://codeforces.com/contest/1182/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pss pair<string, string>
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)1e6+50;

// [num vowels][last ending character]
map<char, vector<string>> a[maxn];
set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int numvowels(string &s) {
    int ret = 0;
    for(char x: s) {
        if(vowels.count(x)) ret++;
    }
    return ret;
}

char lastvowel(string &s) {
    for(int i = sz(s)-1; i >= 0; i--) {
        if(vowels.count(s[i])) return s[i];
    }

    assert(false);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        a[numvowels(s)][lastvowel(s)].emplace_back(s);
    }

    vector<pss> good;
    vector<pss> other;
    for(int i = 1; i <= 1e6; i++) {
        for(char x: vowels) {
            while(sz(a[i][x]) >= 2) {
                string f = a[i][x].back(); a[i][x].pop_back();
                string s = a[i][x].back(); a[i][x].pop_back();

                good.emplace_back(f, s);
            }
        }

        vector<string> arr;
        for(char x: vowels) {
            for(string y: a[i][x]) {
                arr.emplace_back(y);
            }
        }

        while(sz(arr) >= 2) {
            string f = arr.back(); arr.pop_back();
            string s = arr.back(); arr.pop_back();

            other.emplace_back(f, s);
        }
    }

    vector<pair<pss, pss>> ans;
    while(sz(good) and sz(other)) {
        pss f = other.back(); other.pop_back();
        pss s = good.back(); good.pop_back();

        ans.emplace_back(f, s);
    }

    while(sz(good) >= 2) {
        pss f = good.back(); good.pop_back();
        pss s = good.back(); good.pop_back();

        ans.emplace_back(f, s);
    }

    cout << sz(ans) << endl;
    for(auto x: ans) {
        cout << x.fi.fi << " " << x.se.fi << endl;
        cout << x.fi.se << " " << x.se.se << endl;
    }
}

/*

vector<string> a[number of vowels][ending vowel]

think about what to use as the first ones
pairs with different ending vowel but same count are less valuable than pairs with same count and same ending

push all fully complete pairs

first pair fully complete pairs with bad pairs

then pair good pairs with good pairs

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
