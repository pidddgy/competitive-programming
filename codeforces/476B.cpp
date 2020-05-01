// https://codeforces.com/contest/476/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
string s1, s2;

unordered_map<int, int> results;

int eval(string s) {
    return count(s.begin(), s.end(), '+') - count(s.begin(), s.end(), '-');
}

void f(string s) {
    // watch(s)
    if(count(s.begin(), s.end(), '?') == 0) {
        results[eval(s)]++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?') {
            string ne = s, ne2 = s;

            ne[i] = '+';
            ne2[i] = '-';

            f(ne);
            f(ne2);
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;

    int end = 0;
    for(char x: s1) {
        if(x == '+') end++;
        else if(x == '-') end--;
    }

    f(s2);

    ld cases = 0;
    for(pii x: results) {
        cases += x.se;
    }

    cout << fixed << setprecision(15) << results[end]/cases << endl;
}