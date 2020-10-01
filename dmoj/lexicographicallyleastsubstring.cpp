// https://dmoj.ca/problem/bf2hard

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int unsigned long long
// 6918997653319693967
const int MOD = 1e9+7;
const int SEED = 131;
const int MAXN = 1000050;

string s;
int k, N;
int hsh[MAXN];
int seedpow[MAXN];

int getHash(int l, int r) {
    return (hsh[r] - (hsh[l-1] * seedpow[r-l+1]));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    seedpow[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        seedpow[i] = seedpow[i-1]*SEED;
    }

    string s;
    cin >> s;
    
    N = s.size();
    s = "."+s;
    hsh[0] = 1;
    for(int i = 1; i <= N; i++) {
        hsh[i] = (((hsh[i-1]*SEED) + (int)s[i]));
        cerr << hsh[i] << " ";
    }
    cerr << endl;
    int K;
    cin >> K;

    int ind = 1;
    for(int i = 2; i+K-1 <= N; i++) {
        cerr << i << "," << i+3 << " is " << getHash(i, i+K-1) << endl;
        int l = 1;
        int r = K;
        int lastgood = 0;

        while(l <= r) {
            int m = (l+r)/2;
            if(getHash(ind, ind+m-1) == getHash(i, i+m-1)) {
                l = m+1;
                lastgood = m;
            } else {
                r = m-1;
            }
        }

        if(lastgood < K) {
            if(s[ind+lastgood] > s[i+lastgood]) {
                ind = i;
            }
        }
        // if(getHash(i, i+K-1) < mi) {
        //     mi = getHash(i, i+K-1);
        //     ind = i;
        // }
    }

    watch(ind)
    for(int i = ind; i <= ind+K-1; i++) {
        // cerr << "hiiii" << endl;
        cout << s[i];
    }
    cout << endl;




}