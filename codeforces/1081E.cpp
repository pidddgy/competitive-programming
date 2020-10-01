// https://codeforces.com/contest/1081/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

const int maxn = 100500;
ll a[maxn];

void no() {
    cout << "No" << endl;
    exit(0);
}

bool issq(ll a) {
    ll x = sqrt(a);

    return x*x == a;
}

ll sq(ll a) {
    return a*a;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 2; i <= N; i += 2) {
        cin >> a[i];
    }

    ll sum = 0;
    ll cur = 1;
    for(int i = 1; i <= N; i += 2) {
        sum += a[i-1];

        while((sq(cur) <= sum) or !issq(sq(cur)+a[i+1])) {
            cur++;

            if(cur >= 1e7) no();
        }

        a[i] = sq(cur)-sum;
        sum += a[i];
    }

    cout << "Yes" << endl;
    for(int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}