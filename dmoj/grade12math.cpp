// https://dmoj.ca/problem/dmopc19c6p4

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int fuckthiscontest[500500];
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;


    while(Q--) {
        int query;
        cin >> query;

        if(query == 1) {
            int x;
            cin >> x;

            fuckthiscontest[x]++;
        } else if(query == 2) {
            int x;
            cin >> x;

            fuckthiscontest[x]--;
        } else if(query == 3) {
            int l, r, c;
            cin >> l >> r >> c;

            int reeee = 0;
            for(int i = l; i <= r; i++) {
                if(fuckthiscontest[i] == c) {
                    reeee++;
                }
            }

            cout << reeee << endl;
        }
    }
}