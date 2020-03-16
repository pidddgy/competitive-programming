// http://codeforces.com/contest/1186/problem/B

#include <bits/stdc++.h>
#define ll long long
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

ll vert(ll rows) {
    return rows/3;
}

ll hori(ll cols) {
    ll ans = 0;
    ans += cols/2;
    if(cols%2 == 1) ans++;

    return ans;
}

int main() {
    ll rows, cols;
    cin >> rows >> cols;

    ll v = vert(rows);
    ll c = hori(cols);

    ll ret = 0;
    ret += v*c;
    if(rows%3==2) {
        ret += c;
    } else if(rows%3==1) {
        ret += cols/3;
        if(cols%3==2) ret++;
    }

    swap(rows, cols);

    ll ret2 = 0;
    v = vert(rows);
    c = hori(cols);

    ret2 += v*c;
    if(rows%3==2) {
        ret2 += c;
    } else if(rows%3==1) {
        ret2 += cols/3;
        if(cols%3==2) ret2++;
    }


    cout << max(ret, ret2) << endl;

}