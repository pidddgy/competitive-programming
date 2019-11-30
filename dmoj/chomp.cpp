// https://mcpt.ca/problem/lcc19c1s3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

// -1 -> losing position, 0 = not explored, 1 = winning position
map<string, int> dp;
char a[23][23];
int R, C;

void clear() {
    memset(a, 0, sizeof(a));
}

bool winning(string s) {

    if(dp[s] != 0) {
        if(dp[s] == -1) return false;
        else return true;
    }
    // base case
    int cnt = 0;
    for(char x: s) {
        if(x == '1') cnt++;
    }
    if(s[0] == '1' and cnt == 1) {
        // cout << s << s" is base case" << endl;
        dp[s] = -1;
        return false;
    }
    // cout << "HI" << endl;



    vector<string> adj;
    for(int i = 0; i < s.size(); i++) {
        // cout << "HI" << endl;
        for(int j = s[i]-'0'-1; j >= 0; j--) {
            // cout << "hello" << endl;
            // watch(j)s
            // watch(i)
            string n = s;
            for(int k = i; k < s.size(); k++) {
                int v = n[k]-'0';
                if(v-j < 0) {
                    n[k] = '0';
                } else {
                    n[k] = j+'0';
                }
                
            }
            bool nz = false;
            for(char chr: n) {
                if(chr != '0') nz = true;
            }

            // watch(n)
            if(nz) {
                // cout << s << " can go to " << n << endl;
                adj.emplace_back(n);
            }
        }
    }

    for(string x: adj) {
        if(!winning(x)) {
            // cout << s << " can go to " << x << " so " << s << " is winning" << endl;
            dp[s] = 1;
            return true;
        }
    }

    dp[s] = -1;
    return false;
}

void solve() {
    clear();
    cin >> R >> C;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> a[i][j];
        }
    }

    string base = "1";
    for(int i = 1; i <= C-1; i++) {
        base += "0";
    }

    dp[base] = -1;
    
    string st;

    for(int i = 1; i <= C; i++) {
        int cute = 0;
        for(int j = 1; j <= R; j++) {
            if(a[j][i] == '#') {
                cute++;
            }
        }

        st += to_string(cute);
    } 

    if(winning(st)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }


    
}

int main() {
    // cout << winning("11") << endl;
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++) {
        solve();
    } 
}