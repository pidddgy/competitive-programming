// https://codeforces.com/contest/411/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    pii a[10];
    for(int i = 1; i <= 4; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    // 0 = team one winning, 1 = draw, 2 = team two win
    int one = 0, two = 0;

    int A = 0, B = 0, C = 0, D = 0;

    // attack, defense, attack, defense
    if(a[3].se > a[1].se and a[4].fi > a[2].fi) {
        cerr << "hi" << endl;

        one = 2;
    } else if(a[3].se == a[1].se and a[4].fi == a[2].fi) {
        cerr << "hi" << endl;

        one = max(one, 1);
    }

    // attack, defense, defense, attack
    if(a[4].se > a[1].se and a[3].fi > a[2].fi) {
        cerr << "hi" << endl;
        one = 2;
    } else if(a[4].se == a[1].se and a[4].fi == a[2].fi) {
        one = max(one, 1);
    }


    // defense, attack, defense, attack
    if(a[3].fi > a[1].fi and a[4].se > a[2].se) {
        two = 2;
    } else if(a[3].fi == a[1].fi and a[4].se == a[2].se) {
        two = max(two, 1);
    }
    
    // defense, attack attack, defense
    if(a[4].fi > a[1].fi and a[3].se > a[2].se) {
        two = 2;
    } else if(a[4].fi == a[1].fi and a[3].se == a[2].se) {
        two = max(two, 1);
    }

    watch(one)
    watch(two)
    if(one == 0 or two == 0) {
        cout << "Team 1" << endl;
    } else if(one == 1 or two == 1) {
        cout << "Draw" << endl;
    } else {
        cout << "Team 2" << endl;
    }

}