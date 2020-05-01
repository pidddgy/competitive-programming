// https://codeforces.com/contest/923/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr

const int maxn = 100050;

int v[maxn];
int t[maxn];
int tpsa[maxn];

int whole[maxn];
int rem[maxn]; // remainders

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> t[i];
    }

    for(int i = 1; i <= N; i++) {
        tpsa[i] = tpsa[i-1]+t[i];
    }

    for(int i = 1; i <= N; i++) {
        int l = i;
        int r = N;
        int lastgood = -1;

        while(l <= r) {
            int m = (l+r)/2;

            int sum = tpsa[m]-tpsa[i-1];

            if(sum <= v[i]) {
                l = m+1;
                lastgood = m;
            } else {
                r = m-1;
            }
        }

        cerr << "max for " << i << " is " << lastgood << endl;
        if(lastgood == -1) {
            rem[i] += v[i];
        } else {
            whole[i]++;
            whole[lastgood+1]--;
            cerr << "adding " << (v[i]-(tpsa[lastgood]-tpsa[i-1])) << " to " << lastgood+1 << endl;
            rem[lastgood+1] += (v[i]-(tpsa[lastgood]-tpsa[i-1]));
        }
    }

    for(int i = 1; i <= N; i++) {
        whole[i] += whole[i-1];
    }

    for(int i = 1; i <= N; i++) {
        cerr << whole[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= N; i++) {
        cerr << rem[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= N; i++) {
        cout << (t[i]*whole[i])+rem[i] << " ";
    }
    cout << endl;
}