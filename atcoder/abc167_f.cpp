// https://atcoder.jp/contests/abc167/tasks/abc167_f

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

set<int> a[1000050];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> fv, sv;
    for(int i = 1; i <= N; i++) {
        stack<char> st;

        string S;
        cin >> S;

        int f = 0, s = 0;
        for(char x: S) {
            if(x == '(') {
                f++;
            } else if(x == ')') {
                if(f > 0) {
                    f--;
                } else {
                    s++;
                }
            }
        }

        cerr << f << " " << s << endl;
        a[f].emplace(s);
    }

    int need = 0;

    for(int i = 1; i <= N; i++) {
        cerr << "need is " << need << endl;
        if(a[need].empty()) {
            cout << "No" << endl;
            return 0;
        }

        int next = *a[need].begin();
        a[need].erase(a[need].begin());

        need = next;
    }

    if(need) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
