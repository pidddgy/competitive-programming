// https://ecoo.mcpt.ca/problem/ecoo20p4

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pss pair<string, string>
// #define cerr if(false) cerr
#define fi first
#define se second
const int MOD = 1000000007;

// they wouldnt put expletives in the data right
const string GLOBAL_FUNCTION = "FSHITFUCKSDFJFUCK";
int X = 0;
map<string, vector<pss>> funcs;
map<string, int> memo;
template <class T> T addMod(T a, T b, T mod) { T ret = a + b; return ret < mod ? ret : ret - mod; }
template <class T> T subMod(T a, T b, T mod) { T ret = a - b; return 0 <= ret ? ret : ret + mod; }
template <class T> T mulModOvf(T a, T b, T mod) {
    T x = 0;
    for (; b > 0; b >>= 1, a = addMod(a, a, mod)) if (b & 1) x = addMod(x, a, mod);
    return x;
}

int f(string func) {
    int add = 0;
    if(memo.find(func) != memo.end()) {
        // cerr << "skipping" << endl;
        return memo[func];
    }

    for(pss x: funcs[func]) {
        // assert(x.fi != "END");
        if(x.fi == "ADD") {
            // add += stoll(x.se);
            add = addMod(add, stoll(x.se), MOD);
            add %= MOD;
        } else if(x.fi == "SUB") {
            add = subMod(add, stoll(x.se), MOD);
            add %= MOD;
        } else if(x.fi == "MULT") {
            add = mulModOvf(add, stoll(x.se), MOD);
            add %= MOD;
        } else if(x.fi == "CALL") {
            add = addMod(add, f(x.se), MOD);
            add %= MOD;
        }
    }

    memo[func] = add;
    return add;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        X = 0;
        funcs.clear();
        memo.clear();

        int N;
        cin >> N;

        vector<pss> ops;
        for(int i = 1; i <= N; i++) {
            string s;

            cin >> s;

            if(s == "END") ops.emplace_back(s, "n/a");
            else {
                string t;
                cin >> t;

                ops.emplace_back(s, t);
            }

        }

        stack<string> cur;
        cur.push(GLOBAL_FUNCTION);
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i].fi == "FUN") {
                cur.push(ops[i].se);
                continue;
            }

            if(ops[i].fi == "END") {
                cur.pop();
                continue;
            }

            if(ops[i].fi != "FUN") {
                funcs[cur.top()].emplace_back(ops[i]);
            }
        }

        X += f(GLOBAL_FUNCTION);

        cout << X << endl;
    }
}

/*

1
10
FUN INCREMENT
ADD 1
FUN BANANA
ADD 2
END
CALL BANANA
END
CALL INCREMENT
MULT 2
ADD 3

*/