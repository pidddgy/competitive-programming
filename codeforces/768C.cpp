// https://codeforces.com/contest/768/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

int freq[2000], tmp[2000];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        freq[a]++;
    }    


    while(k--) {
        for(int i = 0; i <= 1023; i++) {
            tmp[i] = freq[i];
        }   

        int par = 0;
        for(int i = 0; i <= 1023; i++) {
            if(freq[i]) {
                int next = i^x;
                int change = (freq[i]+(par==0))/2;

                tmp[i] -= change;
                tmp[next] += change;
                par ^= (freq[i]&1);
            }
        }

        for(int i = 0; i <= 1023; i++) {
            freq[i] = tmp[i];
        }
    }

    int mi = INT_MAX, ma = 0;
    for(int i = 0; i <= 1023; i++) {
        if(freq[i]) {
            mi = min(mi, i);
            ma = max(ma, i);
        }
    }

    cout << ma << " " << mi << endl;
}