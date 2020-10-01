// https://codeforces.com/contest/1219/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int L;
string A;

void onezero() {
    string per;
    per += '1';

    for(int i = 0; i < L-1; i++) {
        per += '0';
    }

    string ans;

    while(ans.size() <= A.size()) ans += per;

    cout << ans << endl;
    exit(0);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> L;

    cin >> A;

    if(L > A.size()) {
        cout << 1;
        for(int i = 0; i < L-1; i++) {
            cout << 0;
        }
        cout << endl;
        return 0;
    }

    if(A.size()%L) {
        onezero();
    } else {
        bool all9 = true;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] != '9') all9 = false;
        }

        if(all9) {
            onezero();
        }

        bool needInc = true;
        for(int i = L; i < A.size(); i++) {
            if(A[i] < A[i%L]) {
                needInc = false;
                break;
            } else if(A[i] > A[i%L]) {
                needInc = true;
                break;
            }
        }

        string per;
        for(int i = 0; i < L; i++) {
            per += A[i];
        }

        if(needInc) {
            for(int i = per.size()-1; i >= 0; i--) {
                if(per[i] == '9') {
                    per[i] = '0';
                } else {
                    per[i]++;
                    break;
                }
            }
        }

        string ans = "";
        while(ans.size() < A.size()) {
            ans += per;
        }

        cout << ans << endl;
    }

}