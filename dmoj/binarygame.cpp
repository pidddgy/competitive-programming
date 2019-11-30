// https://dmoj.ca/problem/occ19g3

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int N, k;
string S;
pii r[512];

int f(string st, int val = 0) {
    for(int i = 0; i+k-1 < st.size(); i++) {
         
    }
}

int main() {
    cin >> N >> k;
    cin >> S;

    for(int i = 0; i < pow(2, k); i++) {
        cin >> r[i].fi >> r[i].se;
    }

    cout << f(S) << endl;
}