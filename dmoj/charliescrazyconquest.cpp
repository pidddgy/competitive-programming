// https://dmoj.ca/problem/dmopc19c5p2

#include <bits/stdc++.h>
#define pci pair<char, int>
#define fi first
#define se second
using namespace std;
int main() {
    int N, H;
    cin >> N >> H;

    // if ith turn is dodged
    unordered_map<int, bool> dodge;

    int cHealth = H;
    int oHealth = H;

    pci cmoves[N+5];
    pci omoves[N+5];

    for(int i = 0; i < N+5; i++) {
        cmoves[i].fi = '?';
        omoves[i].fi = '?';
    }

    for(int i = 1; i <= N; i++) {
        cin >> cmoves[i].fi >> cmoves[i].se;
    }

    for(int i = 1; i <= N; i++) {
        cin >> omoves[i].fi >> omoves[i].se;
    }


    for(int i = 1; i <= N; i++) {
        if(cmoves[i].fi == 'A') {
            oHealth -= cmoves[i].se;
        } else if(cmoves[i].fi == 'D') {
            if(omoves[i].fi == 'A') {
                omoves[i].se = 0;
            } else {
                cHealth -= cmoves[i].se;
            }
        }

        if(oHealth <= 0) {
            cout << "VICTORY" << endl;
            return 0;
        } else if(cHealth <= 0){
            cout << "DEFEAT" << endl;
            return 0;
        }

        if(omoves[i].fi == 'A') {
            cHealth -= omoves[i].se;
        } else if(omoves[i].fi == 'D') {
            if(cmoves[i+1].fi == 'A') {
                cmoves[i+1].fi = 0;
            } else {
                oHealth -= omoves[i].se;
            }
        }

        if(oHealth <= 0) {
            cout << "VICTORY" << endl;
            return 0;
        } else if(cHealth <= 0){
            cout << "DEFEAT" << endl;
            return 0;
        }

    }

    cout << "TIE" << endl;


    
}