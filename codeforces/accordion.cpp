// http://codeforces.com/contest/1101/problem/B

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string aqt;
    getline(cin, aqt);

    int lb = -420;
    int lc = -420;

    int rc = -420;
    int rb = -420;

    int i = 0;

    while(i < aqt.size()) {
        if(aqt[i] == '[') {
            lb = i;
            i++;
            break;
        }
        i++;
    }

    while(i < aqt.size()) {
        if(aqt[i] == ':') {
            lc = i;
            i++;
            break;
        }
        i++;
    }

    i = aqt.size()-1;

    while(i >= 0) {
        if(aqt[i] == ']') {
            rb = i;
            i--;
            break;
        }
        i--;
    }
    while(i >= 0) {
        if(aqt[i] == ':') {
            rc = i;
            i--;
            break;
        }
        i--;
    }

    if(lb>=0 && lc>=0 && rc>=0 && rb>=0 && (lc != rc)) {
        int c = 0;
        for(int i = lc; i <= rc; i++) {
            if(aqt[i] == '|')
                c++;
        }
        cout << 4+c << endl;
    } else cout << -1 << endl;
}